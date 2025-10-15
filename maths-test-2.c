#include<stdio.h>
#include<stdlib.h> //random
#include<time.h> //random init
#include<conio.h>//getchar() but no <enter> required
#include<windows.h>//sleep
#define EASYMAX 11
#define MEDMAX 22
#define HARDMAX 33
#define GODMAX 99

main()
{
    srand(time(NULL));
    int n1, n2, n3, n4; // n1, n2 addition, n3 ans, n4 is n3 correct or wrong
    int ans = 1, max; //ans is answer int for code foolproofing only(not shown onscreen) and max holds modulus vals for lvl
    char userans = 'x'; // holds user t/f
    char lvl;// holds e/m/h/g lvl
    int score=0;// for score, timer
    float timer = 5.0;
    printf("Maths Quiz v2\n");
    printf("t for true, f for false or q to exit\n");
    printf("What is your difficulty?(e)asy, m)edium, h)ard or g)od)");
    scanf("%c", &lvl);
    switch(lvl)
    {
        case 'e':
            max = EASYMAX;
            break;
        case 'm':
            max = MEDMAX;
            break;
        case 'h':
            max = HARDMAX;
            break;
        default:
            printf("Entering GOD MODE!!!!\n");
            max = GODMAX;
    }

    while (userans != 'q')
    {
        n1 = rand() % max;
        n2 = rand() % max;
        ans = n1 + n2;
        if((rand() % 2) == 0)
        {
            n3 = n1 + n2;// its the correct ans
        }
        else
        {
            n3 = rand() % max;
            while (n3 == ans)
            {
                n3 = rand() % max;
            }
        }
        timer=5.0;
        printf("%d + %d = %d\n", n1, n2, n3);
        while(kbhit() == 0)
        {
            Sleep(500);
            printf("%1.1f seconds left\r", timer);
            timer = timer- 0.5;
            if (timer == 0)
            {
                printf("\nTime Up. Game Over\n");
                break;
            }
        }
        if (timer <= 0)
        {
            break;
        }
        userans = getch();
        printf("\nProcessing...\n");
        if (userans == 't')
        {
            if (n1 + n2 == n3)
            {
                printf("Correct!\n");
                score++;
                continue;
            }
            else
            {
                printf("Wrong. Game Over\n");
                break;
            }
        }
        else if (userans == 'f')
        {
            if (n1 + n2 != n3)
            {
                printf("Correct!\n");
                score++;
                continue;
            }
            else
            {
                printf("Wrong. Game Over\n");
                break;
            }
        }
        else if (userans == 'q')
        {
            break;
        }
        else
        {
            printf("Unrecognised input. Try again\n");
        }
    }
    printf("Your score is %d\n<Enter> to exit", score);
    getch();
}