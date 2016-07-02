#ifndef MARKDATAANALYSTRFUNCTION_H
#define MARKDATAANALYSTRFUNCTION_H

#define  UDP_DELIMITE_STR  "\1"

inline void ParseValue(double &val, int size , char *str)
{
    val = atof(str);
}

inline void ParseValue(char& val, int size , char *str)
{
    val = str[0];
}

inline void ParseValue(int& val, int size , char *str)
{
    val = atoi(str);
}

inline void ParseValue(float& val, int size, char *str)
{
    val = atof(str);
}

inline void ParseValue(char *val, int size , char *str)
{
    hs_strncpy(val, str, size);
}

inline void ParseValue(unsigned int& val, int size , char *str)
{
    val = 0;
    for(int i= 0; str[i] != 0; i++)
    {
        if('0' <= str[i] && str[i] <= '9')
        {
            val = val * 10 + str[i] - '0';
        }
        else
        {
            val = 0;
            break;
        }
    }
}

#define BEGINPPARSE(type,outdataPtr,indataStrptr, delim) bool __packValid = true; \
    do{   type *__dataptr = outdataPtr; \
    char *__delim = delim; \
    char *__toksaveptr; \
    char *__token;\
    __token = strtok_t(indataStrptr, __delim, &__toksaveptr);

#define PARSEVALUE(val) if( __token != NULL ) \
{   \
    ParseValue(__dataptr->val,sizeof(__dataptr->val), __token); \
    __token = strtok_t(NULL, __delim, &__toksaveptr); \
}else {  __packValid = false; break; }

#define INGOREVALUE(val) if( __token != NULL ) \
{   \
    __token = strtok_t(NULL, __delim, &__toksaveptr); \
}else {  __packValid = false; break; }

#define ENDPARSE }while(0);

#define ISPACKValid  __packValid

#endif
