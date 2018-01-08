#include <iostream>
#include <avm.hpp>
#include <fstream>

#include <avm.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <climits>
#include <cfloat>

#include <IOperand.hpp>
#include <Factory.hpp>
#include <vector>

#include <Int8.hpp>

eOperandType    wichType(const std::string type, const std::string line)
{
    eOperandType    ret = MAX_TYPE;
    int             pos;
    std::string     value;
 
    if (type.empty())
    {
        throw MissingArgument(line);
        return (ret);        
    }
    // if ((pos = type.find(")")) != type.length())
    // {
    //     throw ExtraArgument();
    //     return (ret);  
    // }
    ret = ((pos = type.find("int8")) != -1) ? INT8 :  ret;
    ret = ((ret == MAX_TYPE) && ((pos = type.find("int16")) != -1)) ? INT16 :  ret;
    ret = ((ret == MAX_TYPE) && ((pos = type.find("int32")) != -1)) ? INT32 :  ret;
    ret = ((ret == MAX_TYPE) && ((pos = type.find("float")) != -1)) ? FLOAT :  ret;
    ret = ((ret == MAX_TYPE) && ((pos = type.find("double")) != -1)) ? DOUBLE :  ret;
    return (ret);
}

bool            execute(const std::string cmd, const std::string value, std::vector<IOperand const *> *stack, int line, const std::string l_p)
{
    eOperandType                        t;
    int                                 size_types[5];
    IOperand const *                    a;
    IOperand const *                    b;
    std::string                         sa;
    std::string                         sb;
    static size_t                       id = 1;
    char                                buffer[8];
    long long int                       cmd_hex;

    bzero(buffer, sizeof(buffer));
    strcpy(buffer, cmd.c_str());
    cmd_hex = *((long long int *)&buffer);
    size_types[0] = 5;
    size_types[1] = 6;
    size_types[2] = 6;
    size_types[3] = 6;
    size_types[4] = 7;
    try
    {
        switch (cmd_hex)
        {
            case PUSH_HEX:
            {
                t = wichType(value, l_p);
                if (t >= MAX_TYPE)
                    exit (0);
                (*stack).push_back(Factory::instance()->createOperand(t, value.substr(size_types[t], value.size() - 1)));
                break ;
            }
            case POP_HEX:
            {
                if ((*stack).empty())
                    throw Pop();
                (*stack).pop_back();
                break ;
            }
            case DUMP_HEX:
            {
                for (std::vector<IOperand const *>::iterator it = (*stack).end() - 1; it >= (*stack).begin(); --it) {
                    std::cout << (*it)->toString() << std::endl;
                }
                break ;
            }
            case ASSERT_HEX:
            {
                if ((*stack).empty())
                    throw AssertEmpty();
                if ((t = wichType(value, l_p)) >= MAX_TYPE)
                    throw Type();
                a = Factory::instance()->createOperand(t, value.substr(size_types[t], value.size() - 1));
                sa = a->toString();
                sb = (*stack).back()->toString();
                if (sa != sb)
                    throw WrongAssert();
                delete a;
                break ;
            }
            case ADD_HEX:
            {
                if ((*stack).size() < 2)
                    throw MathError("+");
                a = (*stack).back();
                (*stack).pop_back();
                b = (*stack).back();
                (*stack).pop_back();
                (*stack).push_back(*a + *b);
                delete a; delete b;
                break ;
            }
            case SUB_HEX:
            {
                if ((*stack).size() < 2)
                    throw MathError("-");
                a = (*stack).back();
                (*stack).pop_back();
                b = (*stack).back();
                (*stack).pop_back();
                (*stack).push_back(*a - *b);
                delete a; delete b;
                break ;
            }
            case MUL_HEX:
            {
                if ((*stack).size() < 2)
                    throw MathError("*");
                a = (*stack).back();
                (*stack).pop_back();
                b = (*stack).back();
                (*stack).pop_back();
                (*stack).push_back(*a * *b);
                delete a; delete b;
                break ;
            }
            case DIV_HEX:
            {
                if ((*stack).size() < 2)
                    throw MathError("/");
                a = (*stack).back();
                (*stack).pop_back();
                b = (*stack).back();
                (*stack).pop_back();
                (*stack).push_back(*a / *b);
                delete a; delete b;
                break ;
            }
            case MOD_HEX:
            {
                if ((*stack).size() < 2)
                    throw MathError("%");
                a = (*stack).back();
                (*stack).pop_back();
                b = (*stack).back();
                (*stack).pop_back();
                (*stack).push_back(*a % *b);
                delete a; delete b;
                break ;
            }
            case PRINT_HEX:
            {
                if ((*stack).empty())
                    throw PrintEmpty();
                a = (*stack).back();
                if (a->getType() != INT8)
                    throw Print();
                std::cout << static_cast<Int8 const *>(a)->getValue() << std::endl;
                break ;
            }
            case EXIT_HEX:
                return (true);
            default:
                throw Instruction(wichType(value, l_p));
        }
        ++id;
    }
    catch ( const std::exception& e ) 
    {  
        std::cerr << line << " -> Instruction " << id << " : " << e.what() << std::endl;
        // return (false);
    }
    return (true);
}

bool parseLine(std::string line, std::vector<IOperand const *> *stack, int line_p)
{
    std::string cmd = "";
    std::string value = "";
    int pos;
    int len;

    len = line.length();
    if (line[len - 1] != ')')
        line[len - 1] = '\0' ;

    // std::cerr << line << len <<std::endl;
    if ((pos = line.find("add")) != -1 ||
        (pos = line.find("sub")) != -1 ||
        (pos = line.find("mul")) != -1 ||
        (pos = line.find("dump")) != -1 ||
        (pos = line.find("pop")) != -1 ||
        (pos = line.find("mod")) != -1 ||
        (pos = line.find("div")) != -1 ||
        (pos = line.find("print")) != -1 ||
        (pos = line.find("exit")) != -1)
        cmd = line.substr(pos, line.find(" "));
    else if ((pos = line.find("push")) != -1 ||
        (pos = line.find("assert")) != -1)
    {
        cmd = line.substr(pos, line.find(" "));
        value = line.substr(line.find(" ") + 1);
    }
    else if ((pos = line.find(";")) == 0 || line.empty() || (len - 1) == 0)
        return (true);
    else
        return (false);
    return (execute(cmd, value, stack, line_p, line));
}

bool                inject_file(void)
{
    std::string                     strOneLine;
    int                             pos;
    std::vector<IOperand const *>   stack;
    int                             line_p = 1;

    while (getline(std::cin, strOneLine))
    {
        if ((pos = strOneLine.find(";;")) != -1)
        {
            if (!(parseLine(strOneLine, &stack, line_p)))
                return (false);
        }
    }
    return (true);
}

bool                get_file_contents(const char *filename)
{
    std::vector<IOperand const *>   stack;
    std::string                     strOneLine;
    int                             line_p = 1;

    std::cout << "Opening: " << filename << std::endl;
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
    if (inFile)
    {    
        while (getline(inFile, strOneLine))
        {
            if (!parseLine(strOneLine, &stack, line_p))
                break;
            line_p++;
        }
        inFile.close();
        return(true);
    }
    throw InvalidFile();
}

int                 main(int argc, char const *argv[])
{
    if (argc > 2)
    {
        std::cerr << "Wrong format: " << argv[0] << " <FILE_PATH>" << std::endl;
        return (1);
    }
    else if (argc != 2)
        inject_file();
    else{
        try {
            return (get_file_contents(argv[1]));
        }
        catch ( const std::exception& e ) {
            std::cerr << e.what() << std::endl;
        }
    }
        // get_file_contents(argv[1]);
    return 0;
}
