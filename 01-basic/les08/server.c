#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
const char * ip = "192.168.14.128";
const uint16_t port = 1234;
int main(){
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serv_sock < 0)
	{
		printf("socket error!\n");
		return 0;
	}
    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr(ip);  //具体的IP地址
    serv_addr.sin_port = htons(port);  //端口
    int ret = bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret != 0){
        printf("bind error!\n");
        return 0;
    }
    //进入监听状态，等待用户发起请求
    ret = listen(serv_sock, 20);
    if (ret != 0){
        printf("listen error!\n");
        return 0;
    }
    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
	{
		printf("accept error!\n");
		return 0;
	}
    printf("accept a client: %s\n", inet_ntoa(clnt_addr.sin_addr));
    //向客户端发送数据
    char str[] = "Hello client!";
    char revData[255];
    while(1){
        ret = send(clnt_sock, str, sizeof(str), 0);
        if (ret < 0){
            printf("send error!\n");
            return 0;
        }
        printf("send %d bytes: %s\n",ret,str);  

        ret = recv(clnt_sock,revData,sizeof(revData)/sizeof(char),0);
        if(ret < 0){
            printf("recv copy error!\n");
            return 0;
        }else{
            printf("recv %d bytes: %s\n",ret,revData);
        }
        sleep(1);
    }
    //关闭套接字
    close(clnt_sock);
    close(serv_sock);
    return 0;
}