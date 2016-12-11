%%
username    printf( "%s", getlogin() );
%%
char* getlogin(){
    return "baipeng";
}
int yywrap(){
    return 1;
}
int main(){
    yylex();
    printf("End");
    return 0;

}
