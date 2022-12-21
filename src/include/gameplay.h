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
void init_enemy(ENEMY *E);
void move_enemy(ENEMY *E, VECTOR *Pl);