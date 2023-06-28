//1195. 交替打印字符串 //编写一个可以从 1 到 n 输出代表这个数字的字符串的程序，但是：
//
//如果这个数字可以被 3 整除，输出 "fizz"。
//如果这个数字可以被 5 整除，输出 "buzz"。
//如果这个数字可以同时被 3 和 5 整除，输出 "fizzbuzz"。
//例如，当 n = 15，输出： 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz。
//
//假设有这么一个类：
//
//class FizzBuzz {
//  public FizzBuzz(int n) { ... }               // constructor
//  public void fizz(printFizz) { ... }          // only output "fizz"
//  public void buzz(printBuzz) { ... }          // only output "buzz"
//  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
//  public void number(printNumber) { ... }      // only output the numbers
//}
//请你实现一个有四个线程的多线程版  FizzBuzz， 同一个 FizzBuzz 实例会被如下四个线程使用：
//
//线程A将调用 fizz() 来判断是否能被 3 整除，如果可以，则输出 fizz。
//线程B将调用 buzz() 来判断是否能被 5 整除，如果可以，则输出 buzz。
//线程C将调用 fizzbuzz() 来判断是否同时能被 3 和 5 整除，如果可以，则输出 fizzbuzz。
//线程D将调用 number() 来实现输出既不能被 3 整除也不能被 5 整除的数字。
// 
//
//提示：
//
//本题已经提供了打印字符串的相关方法，如 printFizz() 等，具体方法名请参考答题模板中的注释部分。
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
typedef struct {
	int i;
	int n;
} FizzBuzz;
pthread_mutex_t mutex_t = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
FizzBuzz* fizzBuzzCreate(int n) {
	FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
	obj->n = n;
	obj->i = 1;
	return obj;
}



// printFizz() outputs "fizz".

void printFizz(){
	fprintf(stdout,"fizz\n");
	fflush(stdout);
}
void fizz(FizzBuzz* obj) {
	while(obj->i <= obj->n){
		pthread_mutex_lock(&mutex_t);
		while(obj->i%3 != 0 || obj->i%5 ==0){
			pthread_cond_wait(&cond,&mutex_t);	
			if(obj->i > obj->n){
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex_t);
				pthread_exit(NULL);
			}
		}
		printFizz();
		obj->i = obj->i + 1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex_t);

	}    
}
void * fizzcall(void * obj){
	fizz(obj);
}

void printBuzz(){
	fprintf(stdout,"buzz\n");
	fflush(stdout);
}
// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {


	while(obj->i <= obj->n){
		pthread_mutex_lock(&mutex_t);
		while(obj->i%5 != 0 || obj->i%3 ==0){
			pthread_cond_wait(&cond,&mutex_t);	
			if(obj->i > obj->n){
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex_t);
				pthread_exit(NULL);
			}
		}
		printBuzz();
		obj->i = obj->i+1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex_t);

	}    
}
void * buzzcall(void * obj){
	buzz(obj);
}

// printFizzBuzz() outputs "fizzbuzz".
void printFizzBuzz(){

	fprintf(stdout,"fizzbuzz\n");
	fflush(stdout);
}
void fizzbuzz(FizzBuzz* obj) {

	while(obj->i <= obj->n){
		pthread_mutex_lock(&mutex_t);
		while((obj->i % 3) != 0 || (obj->i % 5) != 0  ){
			pthread_cond_wait(&cond,&mutex_t);	
			if(obj->i > obj->n){
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex_t);
				pthread_exit(NULL);
			}
		}
		printFizzBuzz();
		obj->i = obj->i+1;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex_t);

	}    
}
void * fizzbuzzcall(void * obj){
	fizzbuzz(obj);
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void printNumber(int n){

	fprintf(stdout,"%d\n",n);
	fflush(stdout);
}
void number(FizzBuzz* obj) {

	while(obj->i <= obj->n){
		pthread_mutex_lock(&mutex_t);
		while((obj->i % 3) == 0 || (obj->i % 5) == 0 ){
			pthread_cond_wait(&cond,&mutex_t);	
			if(obj->i > obj->n){
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex_t);
				pthread_exit(NULL);
			}
		}
		if(obj->i <= obj->n){
		printNumber(obj->i);
		}
		obj->i = obj->i + 1;

		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex_t);
	}
}

void * numbercall(void * obj){
	number(obj);
}


void fizzBuzzFree(FizzBuzz* obj) {
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex_t);
	free(obj);
}

int main(int argc, char * argv[]){
	FizzBuzz * fi ;
	fi = malloc(sizeof(fi));
	fi->n = 15;
	pthread_t  one;
	pthread_t  two;
	pthread_t  three;
	pthread_t  four;

	pthread_create(&one, NULL, fizzcall, fi);
	pthread_create(&two, NULL, buzzcall, fi);
	pthread_create(&three, NULL, fizzbuzzcall, fi);
	pthread_create(&four, NULL, numbercall, fi);
	pthread_join(one,NULL);
	pthread_join(two,NULL);
	pthread_join(three,NULL);
	pthread_join(four,NULL);
	exit(0);
}

