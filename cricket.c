#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int runs;
    int balls;
    float strike_rate;
} Batsman;

typedef struct {
    char name[50];
    int overs;
    int runs;
    int wickets;
    float economy;
} Bowler;

Batsman batsmen[11];
Bowler bowlers[11];
int num_batsmen = 0;
int num_bowlers = 0;

void add_batsman(char *name, int runs, int balls) {
    strcpy(batsmen[num_batsmen].name, name);
    batsmen[num_batsmen].runs = runs;
    batsmen[num_batsmen].balls = balls;
    batsmen[num_batsmen].strike_rate = (float)runs / balls * 100;
    num_batsmen++;
}

void add_bowler(char *name, int overs, int runs, int wickets) {
    strcpy(bowlers[num_bowlers].name, name);
    bowlers[num_bowlers].overs = overs;
    bowlers[num_bowlers].runs = runs;
    bowlers[num_bowlers].wickets = wickets;
    bowlers[num_bowlers].economy = (float)runs / overs;
    num_bowlers++;
}

void display_score_sheet() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Time: %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("\nBatsmen\n");
    printf("Name\tRuns\tBalls\tStrike Rate\n");
    for (int i = 0; i < num_batsmen; i++) {
        printf("%s\t%d\t%d\t%.2f\n", batsmen[i].name, batsmen[i].runs, batsmen[i].balls, batsmen[i].strike_rate);
    }

    printf("\nBowlers\n");
    printf("Name\tOvers\tRuns\tWickets\tEconomy\n");
    for (int i = 0; i < num_bowlers; i++) {
        printf("%s\t%d\t%d\t%d\t%.2f\n", bowlers[i].name, bowlers[i].overs, bowlers[i].runs, bowlers[i].wickets, bowlers[i].economy);
    }
}

int main() {
    add_batsman("Sachin Tendulkar", 100, 120);
    add_batsman("Rahul Dravid", 80, 100);
    
    add_bowler("Glenn McGrath", 10, 50, 3);
    add_bowler("Shane Warne", 10, 40, 2);

    display_score_sheet();

    return 0;
}
