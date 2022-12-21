typedef struct
{
    int xv;
    int yv;
}VECTOR;

typedef struct
{
    int xv;
    int yv;
}ENEMY;


void clean_vector(int x, int y);
void move_vector(int key, VECTOR *Pl, long int *score);
void clean_score();
void move_enemy(ENEMY *E, VECTOR *Pl);
void bonusp_p(int x[], int y[], int size);
void print_bonus(int x, int y);