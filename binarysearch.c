#include <stdio.h>
#include <cs50.h>
#include <time.h>

// prototypes
void fill_array(int arr[], int size);
int get_random_term(int length);

int main (int argc, string argv[])
{
    // validate number of  arguments
    if (argc != 2)
    {
        printf("Usage: ./binarysearch <array size> \n");
        return 1;
    }

    // validate length argument
    int len = atoi(argv[1]);
    if (len <= 0)
    {
        printf("Invalid array size argument \n");
        return 2;
    }


    int data[len];
    fill_array(data, len);

    for (int i = 0; i < len; i++)
    {
    printf("%i \n", data[i]);
    }

    int term = get_random_term(len);
    printf("search term %i \n", term);

    return 0;


}

/*
 * Fill an array with ints, with a chance of skipping
 */
void fill_array(int arr[], int len)
{
    int threshold = 20;
    srand(time(NULL));

    for (int i = 0, j = 0; i < len; i++)
    {
        int random;
        do
        {
            random = rand() % 100;
            j++;
        }
        while (random < threshold);

        arr[i] = j;
    }
}

/*
 * Generate the int to search for in the array
 */
int get_random_term(int len)
{
    return rand() % len;
}
