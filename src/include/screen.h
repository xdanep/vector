void start_s();                         // start ncurses
void move_c(int x, int y);              // move pointer
void clear_s();                         // clear screen
void print(const char *type, void *var);                       
void sprint(const char *string);        // print a string in stdout
void scan(const char *type, void *var); // scan from stdin
void refresh_s();                       // refresh window
void exit_s();                          // exit ncurses