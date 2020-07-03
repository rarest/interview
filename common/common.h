//
// Created by HFX on 2020/5/9.
//

#ifndef INTERVIEW_COMMON_H
#define INTERVIEW_COMMON_H

#include <stdint.h>
#include <memory>
#include <iostream>
#include <iomanip>
#include "Logger.h"
#include "def.h"

#ifdef LOGGING_ENABLED
#define LOG(level, msg) interview::level(msg, __FILE__, __LINE__);
#else
#define LOG(level, msg)
#endif /* LOGGING_ENABLED */


#define BEGIN_INTERVIEW_NS namespace interview {
#define END_INTERVIEW_NS }

#define USE_INTERVIEW_NS using namespace interview;

using namespace std;
BEGIN_INTERVIEW_NS
    template<class T>
    void swap(T &val1, T &val2) {
        T tmp = val1;
        val1 = val2;
        val2 = tmp;
    }

    typedef struct SListNode {
        int val = 0;
        SListNode *next = nullptr;
    } SListNode, *PSListNode, **PPSListNode;

    shared_ptr<uint8_t> init_matrix(int w, int h);

    void print_matrix(uint8_t *matrix, int w, int h);


    std::string get_tid();

    extern std::unique_ptr<ILogger> active_logger;

    void debug(const std::string &msg, const std::string &file, std::size_t line);

    void info(const std::string &msg, const std::string &file, std::size_t line);

    void warn(const std::string &msg, const std::string &file, std::size_t line);

    void error(const std::string &msg, const std::string &file, std::size_t line);

END_INTERVIEW_NS



#endif //INTERVIEW_COMMON_H