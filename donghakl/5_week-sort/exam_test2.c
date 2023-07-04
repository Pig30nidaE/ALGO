#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct drawing  drawing;

struct drawing
{
    int  width;    //배경 너비
    int  height;   //배경 높이
    char *matrice; //배경 문자열
};

typedef struct circle  circle;

struct circle
{
   char  type;     //꽉 찬 원인지, 빈 원인지
   float x;        //원 중심의 x축(고정임)
   float y;        //원 중심의 y축(고정임)
   float radius;   //원의 반지름(고정임)
   char  color;    //원을 채우고 있는 문자
};

int ft_strlen(char *str)
{
	if (!str)
		return (0);
	int i = -1;
	while (str[++i]);
	return (i);
}

void print_info(drawing *zone)
{
		int j;

		j = 0;
		while (j < zone->height)
				printf("%.*s\n", zone->width, zone->matrice + (j++ * zone->width));
}

float square(a)
{
		return (a * a);
}

float sq_dist(float x1, float y1, float x2, float y2)
{
		float dist_x;
		float dist_y;

		dist_x = rsquae(x1 - x2);
		dist_y = square(y1 - y2);
		return (dist_x + dist_y);
}

int is_in_circle(float x, float y, circle *circle)
{
		float distance;
		float distance_sqrt;

		distance_sqrt = sqrtf(sq_dist(x, y, circle->x, circle->y));
		distance = distance_sqrt - circle->radius; //중심-좌표 거리 빼기 반지름이
		if (distance <= 0.00000000) //0보다 작거나 같다면
		{
				if (distance <= -1.00000000) //경계거나 안쪽인데 -1보다 작다면
						return (1); // 안쪽이므로 1을 반환하고
				return (2); // 0과 -1사이라면 경계이므로 2 반환.
		}
		return (0); // 0보다 크다면 좌표가 원의 완전한 바깥에 있다는 의미이므로 0 반환
}

void execute_one(circle *circle, drawing *drawing, int x, int y)
{
		int is_in; //좌표의 상태를 나타내줄 정수 변수

		is_in = is_in_circle((float) x, (float) y, circle); //(6) 좌표의 상태 확인
		if (is_in == 2 || (is_in == 1 && circle->type == 'C')) // 해당 상태에 따라
				drawing->matrice[x + y *(drawing->width)] = circle->color; //배경 변경
		return ;
}

int apply_op(drawing *drawing, circle *circle)
{
		int i; //circle->x;
		int j; //circle->y;

		if (circle->radius <= 0.00000000 
					|| (circle->type != 'C' && circle->type != 'c'))
				return (1); //원 조건이 유효하지 않다면 에러 종료
		i = 0;
		while (i < drawing->width) //위에서 아래로 한칸한칸 확인하면서
		{
				j = 0;
				while (j < drawing->height)
						execute_one(circle, drawing, i, j++); //(5) 바꾸는 함수를 실행한다
				i++;
		}
		return (0); //정상 종료
}

int get_info(FILE *file, drawing *drawing)
{
		int  scan_ret; //인자 개수
		int  i;
		char *tmp;
		char background; //배경을 깔아줄 문자

		i = 0;
		scan_ret = fscanf(file, "%d %d %c\n", &drawing->width, &drawing->height \
, &background); // 파일의 첫 줄을 읽어옴
		if (scan_ret == 3) //파일의 첫줄이 유효하다면
		{
				if ((drawing->width < 1) || (drawing->width > 300) \
							|| (drawing->height < 1) || (drawing->height > 300))
						return (1); //배경의 너비, 높이의 조건이 맞지 않다면 에러 종료, 조건이 맞다면
				tmp = (char *)malloc(sizeof(char) * (drawing->width * drawing->height));
				drawing->matrice = tmp; //배경 길이 만큼의 문자열을 선언하고 
				while (i < (drawing->width * drawing->height)) //while문을 돌면서
						drawing->matrice[i++] = background; // 채워줌
				return (0); //정상 종료
		}
		return (1); // 첫줄이 유효하지 않다면	에러 종료	
}

int execute(FILE *file)
{
		int       scan_ret; //파일 인자 개수;
		drawing   drawing; //배경 구성 요소 구조체
		circle 	circle;  //원 구성 요소 구조체
		
		if (!get_info(file, &drawing)) //(3) 파일의 첫 줄과 배경 구조체가 유효하다면
		{
				scan_ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, \
&circle.y, &circle.radius, &circle.color); //둘째 줄을 읽음
				while (scan_ret == 5) // 해당 줄이 유효하다면
				{
						if (apply_op(&drawing, &circle)) //(4) 명령 줄이 유효하지 않다면
								return (1); //에러 종료, 유효하다면 다음줄을 읽음
						scan_ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, \
&circle.x, &circle.y, &circle.radius, &circle.color); 
				}
				if (scan_ret == -1) // 명령 줄을 다 읽었다면
				{
						print_info(&drawing); // (7) 배경을 출력하고
						return (0); // 정상 종료
				}
		}
		return (1); //파일의 첫 줄과 배경 구조체가 유효하지 않다면
}

int main(int argc, char **argv)
{
		int  i;      //에러 처리 문자열 길이 재기
		FILE *file;  //읽어올 파일;

		if (argc == 2) //argv[1]->열 파일의 경로
		{
				file = fopen(argv[1], "r"); //"r", 텍스트 파일
				if (file && !execute(file)) // (2) execute 함수가 0이라면
						return (0); //정상 종료
				i = ft_strlen("Error: Operation file corrupted\n"); //1이라면
				write(1, "Error: Operation file corrupted\n", i); //파일 에러 출력
		}
		else //인자 수가 2가 아니라면
		{
				i = ft_strlen("Error: argument\n");
				write(1, "Error: argument\n", i); //인자 에러 출력
		}
		return (1); // 에러 종료
}