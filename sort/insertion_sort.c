#include <stdio.h>

typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
} recordtype;

void Swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void InsertionSort(recordtype a[], int n){
	int i, j;
	for(i = 0; i < n; i++){
		j = i;
		while((j > 0) && (a[j].key < a[j-1].key)){
			Swap(&a[j], &a[j-1]);
			j--;
		}
	}	
}

void Read_Data(recordtype a[], int *n){
	FILE *f;
	f = fopen("sort.txt", "r");
	int i = 0;
	if(f != NULL){
		while (!feof(f)){
			fscanf(f, "%d%f",&a[i].key, &a[i].otherfields);
			i++;
		}
	} else printf("Loi mo file\n");
	fclose(f);
	*n = i;
}
	
void Print_Data(recordtype a[], int n){
	int i;
	for(i = 0; i < n; i++) 
		printf("%3d%5d%8.2f\n", i+1,a[i].key,a[i].otherfields);
}
	
main(){
	recordtype a[100];
	int n;
	
	printf("Thuat toan Insertion_Sort\n\n");
	Read_Data(a, &n);

	printf("Du lieu truoc khi sap xep:\n");
	Print_Data(a, n);
	 
	InsertionSort(a, n);
	
	printf("Du lieu sau khi sap xep:\n");
	Print_Data(a, n); 
	
	return 0;
}
