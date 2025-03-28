#include <stdio.h>

int main() {
    int frames, i, l, str[100], count = 0, m[10], j, k, exist;

    printf("Enter the length of reference string: ");
    scanf("%d", &l);
    printf("Enter the reference string: ");
    for (i = 0; i < l; i++)
        scanf("%d", &str[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

  
    for (i = 0; i < frames; i++)
        m[i] = -1;

    printf("\nThe page replacement process is....\n");
    for (i = 0; i < l; i++) {
        exist = 0; 
        // Check if the page is already in one of the frames
        for (j = 0; j < frames; j++) {
            if (m[j] == str[i]) {
                exist = 1; // Page hit
                break;
            }
        }

        if (exist == 0) { // Page fault
            m[count % frames] = str[i]; 
            count++;
        }

     
        for (k = 0; k < frames; k++)
            printf("%d\t", m[k]);
        
        if (exist == 0)
            printf("Page fault: %d\n", count);
        else
            printf("HIT\n");
    }

    printf("\nTotal page faults = %d\n", count);
    printf("Total hits = %d\n", l - count);
    printf("Miss ratio: %.2f%%\n", (float)count * 100 / l);
    printf("Hit ratio: %.2f%%\n", (float)(l - count) * 100 / l);

    return 0;
}
