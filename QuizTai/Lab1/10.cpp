void HelpFunc( char * str, int& n ){
    if ( str[n] == '\0'){
        return;
    }
    n ++;
    HelpFunc(str, n);
}

int strLen(char* str)     
{ 
    int res = 0;
    HelpFunc(str, res);
    return res;
} 