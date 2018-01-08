#ifndef AVM_HPP
# define AVM_HPP

#include <string>

// #define AVM_EXTENSION "avm"
// #define COMPILED_EXTENSION "compiled"
#define INT8_HEX 0x0000000038746e69
#define INT16_HEX 0x0000003631746e69
#define INT32_HEX 0x0000003233746e69
#define FLOAT_HEX 0x00000074616f6c66
#define DOUBLE_HEX 0x0000656c62756f64
#define NOP_HEX  0x0000000000706f6e
#define PUSH_HEX 0x0000000068737570
#define POP_HEX 0x0000000000706f70
#define DUMP_HEX 0x00000000706d7564
#define ASSERT_HEX 0x0000747265737361
#define ADD_HEX 0x0000000000646461
#define SUB_HEX 0x0000000000627573
#define MUL_HEX 0x00000000006c756d
#define DIV_HEX 0x0000000000766964
#define MOD_HEX 0x0000000000646f6d
#define PRINT_HEX 0x000000746e697270
#define EXIT_HEX 0x0000000074697865


// typedef bool(*compiler)(std::string &code, const std::string &function, const std::string &type, const std::string &parameter);

// enum functions : unsigned char
// {
//    NOP = 0,
//    PUSH = 1,
//    POP = 2,
//    DUMP = 3,
//    ASSERT = 4,
//    ADD = 5,
//    SUB = 6,
//    MUL = 7,
//    DIV = 8,
//    MOD = 9,
//    PRINT = 10,
//    EXIT = 11,

//    MAX_FUNCTION
// };

// std::string		compile(const std::string &program);
// std::string		extract(const std::string &program, const compiler &compilator);
// bool			   execute(const std::string &code);
// std::string    get_file_contents(const char *filename);
// bool			   put_file_contents(const std::string &content, const std::string &path);
// int			   last_edit(const std::string &file_path);

#endif
