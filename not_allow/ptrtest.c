#include <stdio.h>


int main(int argc, char* argv[]) {
	char *a [ ] = {"China","French","America","German"};  
	char ** s;
	printf(" %s \n %s \n %s \n %s \n", a[0], a[1], a[2], a[3]);
	printf("%p %p %p %p\n",a[0],a[1],a[2],a[3]); //数组元素中保存的地址  
	printf("%p %p %p %p\n",&a[0],&a[1],&a[2],&a[3]);//数组元素单元本身的地址  

	char * b = "pointer to b";
	char c[] = "array c";

	printf("%s \n", b);
	printf("%s \n", c);
	
	c = b;
	


	return 0;


}
