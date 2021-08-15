#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void (*old_fun)(int);

void sigint_handler(int signo)
{
	printf("CTRL+C PRESSED!\n");
	printf("one more press => exit\n");
	//signal(SIGINT, old_fun);
	signal(SIGINT, SIG_DFL);
	while(1){
		printf("i'm in handler\n");
		sleep(1);
	}
}

int main()
{
	old_fun = signal(SIGINT, sigint_handler);
	while(1){
		printf("asdas\n");
		sleep(1);
	}
}


/*
비동기적으로 실행되는 시그널 함수,,,
실행흐름이 궁금하다.
일단 signal을 받으면 현재 하고있는 일을 중지하고 해당 함수를 호출해 처리한다.

https://badayak.com/4447

*/
