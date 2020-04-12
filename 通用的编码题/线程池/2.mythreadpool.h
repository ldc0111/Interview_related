/*************************************************************************
	> File Name: 2.mythreadpool.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 10时58分10秒
 ************************************************************************/

#ifndef _2MYTHREADPOOL_H
#define _2MYTHREADPOOL_H
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
#include <unistd.h>
namespace threadpool{
    class Task{
        public:
        template<typename FUNC,typename ...ARGS>
        Task(FUNC &&F, ARGS&& ...args) {
            func = std::bind(std::forward<FUNC>(F), std::forward<ARGS>(args)...);

        }
        void run(){
            func();
        }
        private:
        std::function<void(void)> func;
    };


    class thread_pool{
        public:
        thread_pool(int size): is_start(false),no_add(false), poolsize(size){}
        void start();
        template<typename FUNC,typename ...ARGS>
        void add(FUNC &&f,ARGS&&...args);
        void stop();
        void thread_loop();
        ~thread_pool();
        private:
        Task * get_one_task();



        bool is_start,no_add;
        int poolsize;
        std::vector<std::thread *> Threads;
        std::queue<Task *> tasks;
        std::mutex tasks_mutex;
        std::condition_variable condition;
    };

    void thread_pool::thread_loop(){
        while(is_start) {
            Task *t = get_one_task();

            if (t != nullptr) {
                //std::cout << "thread_loop tid :" << std::this_thread::get_id() << std::endl;
                t->run();
            }
        }
    }

    Task * thread_pool::get_one_task() {
        std::unique_lock<std::mutex> lock(tasks_mutex);

        while(tasks.empty()&& is_start) {
            condition.wait(lock);//空闲状态都阻塞在这里
        }
        Task *t = nullptr;
        if (!tasks.empty() && is_start) {
            t = tasks.front();
            tasks.pop();
        }
        return t;
    }

    void thread_pool::start(){
        std::unique_lock<std::mutex> lock(tasks_mutex);
        is_start = true;
        no_add = false;//可以添加
        for (int i = 0; i < poolsize; i++) {
            Threads.push_back(new std::thread(&thread_pool::thread_loop,this));
        }
    }


    template<typename FUNC,typename ...ARGS>
    void thread_pool::add(FUNC &&f,ARGS&&...args){
        std::unique_lock<std::mutex> lock(tasks_mutex);
        if (no_add) return ;//已经执行stop 禁止添加任务
        tasks.push(new Task(std::forward<FUNC>(f),std::forward<ARGS>(args)...));

        condition.notify_one();

        return ;

    }

    void thread_pool::stop(){
        while(is_start) {
            std::unique_lock<std::mutex> lock(tasks_mutex);
            no_add = true;//禁止添加任务
            if (tasks.empty()){
                is_start = false;
                condition.notify_all();
            }
            //这里可以睡一秒后再获取互斥锁
        }
        for (int i = 0; i < Threads.size(); i++) {
            Threads[i]->join();
            delete Threads[i];
        }
        Threads.clear();
    }

    thread_pool::~thread_pool(){
        stop();
    }

}

#endif
