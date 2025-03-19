#include <stdio.h>

int main(void)
{
    int seats;
    int votes;
    int lists;
    printf("Total number of seats: ");
    scanf("%d", &seats);
    printf("Total number of votes: ");
    scanf("%d", &votes);
    printf("Total number of lists: ");
    scanf("%d", &lists);
    int quota = votes / seats;

    for (int list = 0; list < lists; list++)
    {
        int vote;
        printf("Votes for list %d: ", list + 1);
        scanf("%d", &vote);
        printf("Automatic seat for list %d: %d\n", list + 1, vote / quota);
        printf("Remainder for list %d: %d\n", list + 1, vote % quota);
    }

    return 0;
}
