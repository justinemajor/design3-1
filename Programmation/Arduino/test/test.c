#include <stdio.h>

// int main(){

//     int a[3][3], i, j;
//     float determinant=0;

//     printf("Enter the 9 elements of matrix: ");
//     for(i=0; i<3; i++)
//         for(j=0; j<3; j++)
//             scanf("%d", &a[i][j]);

//     printf("\nTest is:\n");
//     printf("%d ", a[0]);
//     printf("\nThe matrix is\n");
//     for(i=0; i<3; i++){
//         printf("\n");
//         for(j=0; j<3; j++)
//             printf("%d\t", a[i][j]);
//     }

//     for(i=0; i<3; i++)
//         determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

//     printf("\nInverse of matrix is: \n\n");
//     for(i=0; i<3; i++){
//         for(j=0; j<3; j++)
//             printf("%.2f\t",((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant);
//         printf("\n");
//     }

//     return 0;
// }

int main() {
    int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int even[10], odd[10];
    int loop, e, d;

    e = d = 0;

    for(loop = 0; loop < 10; loop++) {
        if(array[loop]%2 == 0) {
            even[e] = array[loop];
            e++;
        } else {
            odd[d] = array[loop];
            d++;
        }
    }

    printf(" original -> ");

    for(loop = 0; loop < 10; loop++)
        printf(" %d", array[loop]);
        
    printf("\n even -> ");

    for(loop = 0; loop < e; loop++)
        printf(" %d", even[loop]);   

    printf("\n odd -> ");

    for(loop = 0; loop < d; loop++)
        printf(" %d", odd[loop]);   

    return 0;
}
