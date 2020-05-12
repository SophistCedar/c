#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
const char *ip = "192.168.14.128";
const uint16_t port = 1234;
int main(){
    //创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
		printf("socket error!\n");
		return 0;
	}
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr(ip);  //具体的IP地址
    serv_addr.sin_port = htons(port);  //端口
    int ret = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret != 0){
        printf("connect error!\n");
        return 0;
    }
    //读取服务器传回的数据
    char buffer[255];
    char str[] = "Hello server!";
    while(1){
        ret = recv(sock, buffer, sizeof(buffer),0);
        if(ret < 0){
            printf("recv error!\n");
            return 0;
        }
        printf("recv %d bytes: %s\n",ret,buffer);  
        
        ret = send(sock, str, sizeof(str),0);
        if (ret < 0){
            printf("send error!\n");
            return 0;
        }
        printf("send %d bytes: %s\n",ret,str);  

        sleep(1);
    }
    //关闭套接字
    close(sock);
    return 0;
}