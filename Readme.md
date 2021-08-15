# getpid
sys/tpyes.h, unistd.h 헤더를 이용
pid_t getpid(void) 함수를 통해 pid 반환받기
getppid 함수는 부모 프로세스의 id를 구해준다.

₩₩₩c


₩₩₩

버퍼를 공유메모리로 만들어서 전달할 수 있다.
write
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit

# Signal이란?

Signal이란 Software Interrupt로, process에 무엇인가 발생했음을 알리는 간단한 메시지를 비동기적으로 보내는 것이다.
Signal을 받은 프로세스는 Signal에 따른 미리 지정된 기본 동작을 수행할 수도, 지정한 함수에 의해 무시할 수도, 특별한 처리를 할 수 도 있다.

1) kill 함수

 - 헤더 파일 <sys/types.h>, <signal.h>

 - 함수 원형 : int kill(pid_t pid, int sig)

 - 첫번째 파라미터 pid : 시그널을 받을 프로세스의 id.

 - 두번째 파리미터 sig : pid로 지정된 프로세스에 보내려는 시그널.

 - pid > 0 인 경우에는 pid로 지정한 프로세스에게 시그널을 보낸다.


1. libft를 고치고 활용한다.
LIBS = -Linclude/libft -lft

-L(라이브러리 디렉토리) -l(라이브러리명)

2. 코드짜고 makefile

https://randstrgen.lazyig.com/ => 랜덤문자열생성기

char *decorate(const char *str, int client_pid)
{
	msg = ">[" + ft_itoa(client_pid) + "]\n";
	ft_itoa(client_pid);
}

음, pid의 유효범위를 지정해주고 범위를 벗어났을 때의 오류처리가 필요하겠군!
