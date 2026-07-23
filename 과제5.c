#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _Address { //주소에 대한 구조체
	char country[30];
	char state[30];
	char city[30];
	char district[30];
}Address;

typedef struct _Student {//학생 정보에 대한 구조체
	int num;
	char name[20];
	int grade;
	Address address;
}Student;

Student s[100];

void stu_array(FILE* F); //학생 정렬 함수 선언
void stu_found(FILE* F);//학생 찾는 함수 선언
void stu_add_delet(FILE* F);//학생 추가, 삭제하는 함수 선언

int strcmp(const char* a, const char* b); //두 함수 길이 비교하는 함수 선언
int string(char* a, char* b);//두 함수 동일여부 판단하는 함수 선언

int main()
{
	int function; //출석부 프로그램 기능 선택값 저장하는 변수 선언

	while (1) //무한반복
	{
		FILE* F;
		F = fopen("과제5_메모장.txt", "r"); //파일 열기

		printf("출석부 프로그램 기능을 선택하세요.\n");
		printf("1. 학생 정렬  2. 학생 찾기  3. 학생 추가, 삭제  4. 종료 : ");
		scanf("%d", &function);

		if (function == 1) //학생정렬 선택했다면
			stu_array(F);//학생 정렬 함수 호출

		else if (function == 2) //학생찾기 선택했다면
			stu_found(F);//학생 찾기 함수 호출

		else if (function == 3)//학생 추가, 삭제 선택했다면
			stu_add_delet(F);//학생추가, 삭제 함수 호출

		else if (function == 4)//종료 선택했다면
			break;//종료
	}
	return 0;
}

void stu_array(FILE* F)//학생 정렬함수
{
	F = fopen("과제5_메모장.txt", "r");//읽기 전용 파일 열기
	if (F == NULL)//파일에 아무것도 없다면
	{
		printf("파일이 존재하지 않습니다. 다시 입력하세요. \n");
		return;
	}

	int count = 0; //파일에 들어있는 값 개수 저장하는 변수 선언

	while (fscanf(F, "%d %s %s %s %s %s %d", &s[count].num, s[count].name, s[count].address.country, s[count].address.state, s[count].address.city, s[count].address.district, &s[count].grade) == 7)//입력값이 모두 7개일때까지 반복
		count++; //개수+1

	fclose(F);//파일 닫기

	if (count == 0) //파일의 값 개수가 없다면
	{
		printf("정렬할 학생이 없습니다. \n");
		return;
	}

	int option; //학생 정렬 방법 옵션 저장하는 변수 선언
	int add_option = 0; //주소에 대한 상세 옵션 저장 변수 선언
	printf("학생 정렬 방법을 고르세요.\n");
	printf("1.번호순  2.이름순  3.주소순  4.성적순 : ");
	scanf("%d", &option);

	if (option == 3) //주소를 택했다면
	{
		printf("주소 정렬방식을 선택하세요.\n");//상세주소 택하기
		printf("1. 나라  2. 도  3.시  4.구 : ");
		scanf("%d", &add_option);
	}

	for (int i = 0; i < count - 1; i++)//특정 배열의
	{
		for (int j = i + 1; j < count; j++) //오른쪽의 배열과 비교
		{
			switch (option) //옵션에 대해 택한 숫자에 대한 switch함수
			{
			case 1: //번호 택
				if (s[i].num > s[j].num)//앞선 번호가 더 크다면
				{
					//두 배열 전체 교환
					Student temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
				break;

			case 2://이름 택
				if (strcmp(s[i].name, s[j].name) == 1)//앞선 이름의 한글이 더 뒤에 있다면
				{
					//두 배열 전체 교환
					Student temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
				break;

			case 3://주소택
			{
				switch (add_option) //주소 상세 옵션에 대한 switch함수
				{
				case 1://나라 택
					if (strcmp(s[i].address.country, s[j].address.country) == 1)//앞선 나라의 한글이 더 뒤에 있다면
					{
						//두 배열 전체 교환
						Student temp = s[i];
						s[i] = s[j];
						s[j] = temp;
					}
					break;

				case 2://도 택
					if (strcmp(s[i].address.state, s[j].address.state) == 1)//앞선 도의 한글이 더 뒤에 있다면
					{
						//두 배열 전체 교환
						Student temp = s[i];
						s[i] = s[j];
						s[j] = temp;
					}
					break;

				case 3://시 택
					if (strcmp(s[i].address.city, s[j].address.city) == 1)//앞선 시의 한글이 더 뒤에 있다면
					{
						//두 배열 전체 교환
						Student temp = s[i];
						s[i] = s[j];
						s[j] = temp;
					}
					break;

				case 4://구 택
					if (strcmp(s[i].address.district, s[j].address.district) == 1)//앞선 구의 한글이 더 뒤에 있다면
					{
						//두 배열 전체 교환
						Student temp = s[i];
						s[i] = s[j];
						s[j] = temp;
					}
					break;
				}
			}
			break;

			case 4://성적 택
				if ((s[i].grade > s[j].grade))//앞선 성적이 더 크다면
				{
					//두 배열 전체 교환
					Student temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
				break;
			}
		}
	}

	printf("정렬 : \n");
	for (int i = 0; i < count; i++)//파일의 값 개수만큼
	{
		printf("%d %s %s %s %s %s %d\n", s[i].num, s[i].name, s[i].address.country, s[i].address.state, s[i].address.city, s[i].address.district, s[i].grade);
	}
}

void stu_found(FILE* F) //학생 찾는 함수
{
	F = fopen("과제5_메모장.txt", "r"); //읽기 전용 파일 열기
	if (F == NULL)//파일 값이 존재하지 않는다면
	{
		printf("파일이 존재하지 않습니다. 다시 입력하세요. \n");
		return;
	}

	int count = 0; //파일에 들어있는 값 개수 저장하는 변수 선언

	while (fscanf(F, "%d %s %s %s %s %s %d", &s[count].num, s[count].name, s[count].address.country, s[count].address.state, s[count].address.city, s[count].address.district, &s[count].grade) == 7)
		count++;//파일 값 개수 +1

	fclose(F); //파일 닫기

	int found_option; //학생 찾는 옵션 저장하는 변수 선언
	int found_num; //번호로 찾을 시, 입력할 번호 저장 변수 선언

	int found_adress_option;//주소로 찾을 때 상세 변수 선언
	char found_adress_country[30];//나라로 주소 찾을 때 저장 변수 선언 
	char found_address_state[30];//도로 주소 찾을 때 저장 변수 선언 
	char found_address_city[30];//시로 주소 찾을 때 저장 변수 선언 
	char found_address_district[30];//구로 주소 찾을 때 저장 변수 선언 
	int found_grade; //성적으로 찾을시 입력할 번호 저장 변수 선언

	printf("학생을 찾을 요소를 정하세요. \n");
	printf("1. 번호  2. 주소  3. 성적 : ");
	scanf("%d", &found_option);

	switch (found_option)//학생을 찾을 옵션 선택에 따른 switch함수
	{
	case 1: //번호로 찾기
	{
		printf("번호를 입력하세요. : ");
		scanf("%d", &found_num);

		for (int i = 0; i < count; i++) //파일 개수만큼 반복해서 입력값과 비교
		{
			if (s[i].num == found_num) //입력번호와 같다면
				printf("%s ", s[i].name);
		}
		printf("\n");
	}
	break;

	case 2://주소로 찾기
	{
		printf("상세 주소 옵션을 고르세요.\n");
		printf("1. 나라  2. 도  3. 시  4.구 : ");
		scanf("%d", &found_adress_option);

		switch (found_adress_option)//상세 주소 옵션에 따른 switch
		{
		case 1://나라로 찾기
		{
			printf("나라를 입력하세요. : ");
			scanf("%s", found_adress_country);

			for (int i = 0; i < count; i++)//파일 개수만큼 반복해서 입력값과 비교
			{
				if (string(s[i].address.country, found_adress_country))//입력번호와 같다면
				{
					printf("%s ", s[i].name);
				}
			}
			printf("\n");
		}
		break;

		case 2://도로 찾기
		{
			printf("도를 입력하세요 : ");
			scanf("%s", found_address_state);

			for (int i = 0; i < count; i++)//파일 개수만큼 반복해서 입력값과 비교
			{
				if (string(s[i].address.state, found_address_state))//입력번호와 같다면
				{
					printf("%s ", s[i].name);
				}
			}
			printf("\n");
		}
		break;

		case 3://시로 찾기
		{
			printf("시를 입력하세요 : ");
			scanf("%s", found_address_city);

			for (int i = 0; i < count; i++)//파일 개수만큼 반복해서 입력값과 비교
			{
				if (string(s[i].address.city, found_address_city))//입력번호와 같다면
				{
					printf("%s ", s[i].name);
				}
			}
			printf("\n");
		}
		break;

		case 4://구로 찾기
		{
			printf("구를 입력하세요 : ");
			scanf("%s", found_address_district);

			for (int i = 0; i < count; i++)//파일 개수만큼 반복해서 입력값과 비교
			{
				if (string(s[i].address.district, found_address_district))//입력번호와 같다면
				{
					printf("%s ", s[i].name);
				}
			}
			printf("\n");
		}
		break;
		}
	}
	break;

	case 3://성적으로 찾기
	{
		printf("성적(정수)을 입력하세요. : "); //정수인 성적 입력받기
		scanf("%d", &found_grade);

		for (int i = 0; i < count; i++)//파일 개수만큼 반복해서 입력값과 비교
		{
			if (s[i].grade == found_grade)//입력번호와 같다면
			{
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	break;
	}
}

void stu_add_delet(FILE* F)//학생 추가, 삭제하는 함수
{
	F = fopen("과제5_메모장.txt", "r"); //읽기 전용 파일 열기

	int count = 0;//파일에 들어있는 값 개수 저장하는 변수 선언

	if (F != NULL)//파일 값이 있다면
	{
		while (fscanf(F, "%d %s %s %s %s %s %d", &s[count].num, s[count].name, s[count].address.country, s[count].address.state, s[count].address.city, s[count].address.district, &s[count].grade) == 7)//파일의 학생 정보가 다 있다면 반복
			count++;//파일의 값 개수 +1

		fclose(F);//파일 닫기
	}

	int stu_add_delet_option;//학생 추가할지 삭제할지에 대한 옵션 저장 변수 선언
	printf("학생 추가, 삭제 중 선택하세요.\n");
	printf("1. 추가  2. 삭제 : ");
	scanf("%d", &stu_add_delet_option);

	int delet_num; //숫자 지우기 변수 선언
	char delet_name[30];//이름 지우기 변수 선언
	char delet_address_country[30];//주소-나라 지우기 변수 선언
	char delet_address_state[30];//주소-도 지우기 변수 선언
	char delet_address_city[30];//주소-시 지우기 변수 선언
	char delet_address_district[30];//주소-구 지우기 변수 선언
	int delet_grade;//성적 지우기 변수 선언

	int found_index = -1;//찾은 값의 인덱스를 일단 음수로 초기화.(인덱스 겹침 방지 위해)

	switch (stu_add_delet_option)//학생 추가할지 삭제할지에 대한 옵션 저장 변수에 따른 swutch
	{
	case 1: //추가
	{
		printf("학생을 추가하겠습니다. 정보를 입력해주세요. \n");
		printf("번호 : ");
		scanf("%d", &s[count].num);
		printf("이름 : ");
		scanf("%s", s[count].name);
		printf("주소--나라 : ");
		scanf("%s", s[count].address.country);
		printf("	--도 : ");
		scanf("%s", s[count].address.state);
		printf("	--시 : ");
		scanf("%s", s[count].address.city);
		printf("	--구 : ");
		scanf("%s", s[count].address.district);
		printf("성적 : ");
		scanf("%d", &s[count].grade);

		count++;//파일 값 개수+1
	}
	break;

	case 2://삭제
	{
		printf("삭제할 학생의 번호, 이름, 주소, 성적을 입력하세요. : ");
		scanf("%d %s %s %s %s %s %d", &delet_num, delet_name, delet_address_country, delet_address_state, delet_address_city, delet_address_district, &delet_grade);

		for (int i = 0; i < count; i++)
		{
			if (delet_num == s[i].num && string(delet_name, s[i].name) && string(delet_address_country, s[i].address.country) && string(delet_address_state, s[i].address.state) && string(delet_address_city, s[i].address.city) && string(delet_address_district, s[i].address.district) && delet_grade == s[i].grade) //입력값이 파일 값과 일치한다면
			{
				found_index = i;//그 인덱스 값을 저장
				break;
			}
				printf("입력된 정보에 해당하는 학생이 없습니다.\n");
		}
		if (found_index != -1)//삭제할 정보를 찾았다면
		{
			for (int i = found_index; i < count - 1; i++)//삭제할 정보의 인덱스부터
			{
				s[i] = s[i + 1];//한칸씩 앞으로 당기기
			}
			count--;//파일 값 개수 -1
			printf("학생이 삭제되었습니다. \n");
		}
		else
			printf("입력된 정보에 해당하는 학생이 없습니다.\n");
	}
	break;
	}

	F = fopen("과제5_메모장.txt", "w");//쓰기 전용 파일 열림

	if (F == NULL)//파일이 없다면
	{
		printf("파일에 정보가 없습니다. \n");
		return;
	}

	for (int i = 0; i < count; i++) //파일 값 개수만큼
	{
		fprintf(F, "%d %s %s %s %s %s %d\n", s[i].num, s[i].name, s[i].address.country, s[i].address.state, s[i].address.city, s[i].address.district, s[i].grade);
	}
	fclose(F);//파일 닫기
}

int strcmp(const char* a, const char* b) //두 배열 길이, 선후 비교하는 함수 선언
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') //두 배열 모두 NULL이 아닐때
	{
		if (a[i] > b[i])//앞의 배열이 뒤의 배열보다 길다면
			return 1;//'거꾸로 됐다' 반환

		if (a[i] < b[i])//앞의 배열이 뒤의 배열보다 짧다면
			return 0;//'제대로 있다' 반환

		i++; //i증가
	}
	if (a[i] != '\0' && b[i] == '\0')//앞선 배열이 NULL이 아니고 뒤의 배열이 NULL인 경우 (그 전까지의 값들을 다 같아도)
		return 1; //'거꾸로 됐다' 반환

	return 0;//'제대로 있다' 반환
}

int string(char* a, char* b) //두 배열 동일여부 판단하는 함수 선언
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')//두 배열 모두 NULL이 아닐때
	{
		if (a[i] != b[i]) return 0; // 한 글자라도 다르면 0으로 반환
		i++;//i증가
	}

	if (a[i] == '\0' && b[i] == '\0') return 1;// 둘 다 동시에 끝났는지 확인

	return 0;
}