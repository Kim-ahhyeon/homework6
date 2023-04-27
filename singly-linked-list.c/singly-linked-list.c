/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �꾩슂�� �ㅻ뜑�뚯씪 異붽� */

typedef struct Node {  
	int key;            //정수 변수 key 선언
	struct Node* link;  //구조체 포인터 노드 *link 선언
} listNode;  //구조체 이름은 listNode

typedef struct Head { //
	struct Node* first; //구조체 포인터 노드 *first 선언
}headNode;   //구조체 이름은 headNode


/* �⑥닔 由ъ뒪�� */
headNode* initialize(headNode* h); //
int freeList(headNode* h);

int insertFirst(headNode* h, int key); //함수 inserfFirst 정의, 매개변수 headNode* h, int key
int insertNode(headNode* h, int key); //함수 insertNode 정의, 매개변수 headNode* h, int key
int insertLast(headNode* h, int key); //insertLast(headNode* h, int key

int deleteFirst(headNode* h);         //함수 deleteFirst 정의, 매개변수 eadNode* h
int deleteNode(headNode* h, int key); //함수 deleteNode 정의, 매개변수 headNode* h, int key
int deleteLast(headNode* h);          //함수 deleteLast 정의, 매개변수 headNode* h
int invertList(headNode* h);          //함수 invertList 정의, 매개변수 headNode* h

void printList(headNode* h);

int main()
{
	char command;  //문자형 변수 command 선언
	int key;       //정수형 변수 key 선언
	headNode* headnode=NULL;  //headNode형 변수 *headnode 선언, Null로 초기화

    printf("[----- [Kim ah hyeon]] [2022041010 -----]\n");

	do{
		printf("----------------------------------------------------------------\n");  //---------------------------------------------------------------- 출력
		printf("                     Singly Linked List                         \n");  //                     Singly Linked List                          출력
		printf("----------------------------------------------------------------\n");  //---------------------------------------------------------------- 출력
		printf(" Initialize    = z           Print         = p \n");  // Initialize    = z           Print         = p  출력
		printf(" Insert Node   = i           Delete Node   = d \n");  // Insert Node   = i           Delete Node   = d  출력
		printf(" Insert Last   = n           Delete Last   = e\n"); // Insert Last   = n           Delete Last   = e 출력
		printf(" Insert First  = f           Delete First  = t\n");  // Insert First  = f           Delete First  = t 출력
		printf(" Invert List   = r           Quit          = q\n");  // Invert List   = r           Quit          = q 출력
		printf("----------------------------------------------------------------\n");  //---------------------------------------------------------------- 출력

		printf("Command = ");  //Command = 출력
		scanf(" %c", &command);  //command 입력받음.

		switch(command) {                  // 제어식 command
		case 'z': case 'Z':                //command가 'z'또는 'Z'일 경우
			headnode = initialize(headnode); //headnode에 initialize(headnode) 대입
			break;                         //break문
		case 'p': case 'P':                //command가 'p' 또는 'P'일 경우
			printList(headnode);           //printList(headode) 함수 호출
            break;                         //break문
		case 'i': case 'I':                //command가 'p' 또는 'P'일 경우
			printf("Your Key = ");         //Your Key = 출력
			scanf("%d", &key);             //key 값을 입력받음
			insertNode(headnode, key);     //insertNode(headnode, key)함수 호출
			break;                         //break문
		case 'd': case 'D':                //command가 'd' 또는 'D'일 경우
			printf("Your Key = ");         //Your Key = 출력
			scanf("%d", &key);             //key 값을 입력받음
			deleteNode(headnode, key);     //deleteNode(headnode, key) 함수 호출
			break;                         //break문
		case 'n': case 'N':                //command가 'n' 또는 'N'일 경우
			printf("Your Key = ");         //Your Key = 출력
			scanf("%d", &key);             //key 값을 입력받음
			insertLast(headnode, key);     //insertLast(headnode, key) 함수 호출
			break;                         //break문
		case 'e': case 'E':                //command가 'e' 또는 'E'일 경우
			deleteLast(headnode);          //deleteLast(headnode) 함수 호출
			break;                         //break문
		case 'f': case 'F':                //command가 'f' 또는 'F'일 경우
			printf("Your Key = ");         //Your Key = 출력
			scanf("%d", &key);             //key 값을 입력받음
			insertFirst(headnode, key);    //insertFirst(headnode, key) 함수 호출
			break;                         //break문
		case 't': case 'T':                //command가 't' 또는 'T'일 경우
			deleteFirst(headnode);         //deleteFirst(headnode) 함수 호출
			break;                         //break문
		case 'r': case 'R':                //command가 'r' 또는 'R'일 경우
			invertList(headnode);          //invertList(headnode) 함수 호출
			break;                         //break문
		case 'q': case 'Q':                //command가 'q' 또는 'Q'일 경우
			freeList(headnode);            //freeList(headnode) 함수 호출
			break;                         //break문
		default:                           //case가 위 경우 모두 아닐 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");  //       >>>>>   Concentration!!   <<<<<      출력
			break;                         //break문
		}

	}while(command != 'q' && command != 'Q');  //command가 'q'가 아니거나 'Q'가 아니라면 실행

	return 1;    //1 값 반환
}

headNode* initialize(headNode* h) {

	/* headNode媛� NULL�� �꾨땲硫�, freeNode瑜� �몄텧�섏뿬 �좊떦�� 硫붾え由� 紐⑤몢 �댁젣 */
	if(h != NULL)  //h가 NULL이 아니라면
		freeList(h);  //함수 freeList 호출

	/* headNode�� ���� 硫붾え由щ� �좊떦�섏뿬 由ы꽩 */
	headNode* temp = (headNode*)malloc(sizeof(headNode)); //headNode *temp를 동적할당함
	temp->first = NULL; //temp->first를 NULL로 초기화
	return temp;        //temp를 반환함
}

int freeList(headNode* h){
	/* h�� �곌껐�� listNode 硫붾え由� �댁젣
	 * headNode�� �댁젣�섏뼱�� ��.
	 */
	listNode* p = h->first;  //listNode *p를 h->first로 초기화

	listNode* prev = NULL;  //listNode *prev를 NULL로 초기화
	while(p != NULL) {      //p가 NULL이 아니면 반복
		prev = p;           //prev에 p 대입
		p = p->link;        //p에 p->link 대입
		free(prev);         //prev 메모리 해제
	}  
	free(h);                //h 메모리 해제
	return 0;               //0 값 반환
}


/* 由ъ뒪�몃� 寃��됲븯��, �낅젰諛쏆� key蹂대떎 �곌컪�� �섏삤�� �몃뱶 諛붾줈 �욎뿉 �쎌엯 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));//listNode* node 동적할당함
	node->key = key;//node->key에 key 대입
	node->link = NULL;//node->link를 NULL로 초기화

	if (h->first == NULL)  //h->first가 NULL이라면
	{
		h->first = node;  //h->first에 node 대입
		return 0;  //0 값 반환
	}

	listNode* n = h->first;  //listNode* n에 h->first 대입
	listNode* trail = h->first; //listNode* trail에 h->first 대입

	/* key瑜� 湲곗��쇰줈 �쎌엯�� �꾩튂瑜� 李얜뒗�� */
	while(n != NULL) { //n이 NULL이 아닐 경우 반복
		if(n->key >= key) {  //n->key가 key보다 같거나 크다면
			/* 泥� �몃뱶 �욎そ�� �쎌엯�댁빞�� 寃쎌슦 �몄� 寃��� */
			if(n == h->first) {   //n이 h->first와 같다면
				h->first = node;  //h->first에 node 대입
				node->link = n;  //node->link에 n 대입
			} else { /* 以묎컙�닿굅�� 留덉�留됱씤 寃쎌슦 */
				node->link = n;  //node->link에 n 대입
				trail->link = node;  //trail->link에 node 대입
			}
			return 0;  //0으로 반환
		}

		trail = n;  //trail n으로 초기화
		n = n->link;//n n->link로 초기화
	}

	/* 留덉�留� �몃뱶源뚯� 李얠� 紐삵븳 寃쎌슦 , 留덉�留됱뿉 �쎌엯 */
	trail->link = node;  //trail->link를 node로 초기화
	return 0; //0으로 반환
}

/**
 * list�� key�� ���� �몃뱶�섎굹瑜� 異붽�
 */
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode* node 동적할당
	node->key = key; //node->key에 key 값 대입
	node->link = NULL; //node->link NULL로 초기화

	if (h->first == NULL) //h->first가 NULL이라면
	{
		h->first = node; //h->first에 node 대입
		return 0; //0으로 반환
	}

	listNode* n = h->first; //listNode* n에 h->first 대입
	while(n->link != NULL) { //n->link가 NULL이 아니라면 반복
		n = n->link; //n에 n->link 대입
	}
	n->link = node; //n->link에 node 대입
	return 0; //0으로 반환
}

/**
 * list 泥섏쓬�� key�� ���� �몃뱶�섎굹瑜� 異붽�
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode* node 동적할당
	node->key = key; //node->key에 key 값 대입

	node->link = h->first; //node->link에 h->first 대입
	h->first = node; //h->first에 node 대입

	return 0; //0으로 반환
}

/**
 * list�먯꽌 key�� ���� �몃뱶 ��젣
 */
int deleteNode(headNode* h, int key) {

	if (h->first == NULL) //h->fitst가 NULL이라면
	{
		printf("nothing to delete.\n"); //nothing to delete. 출력
		return 0; //0 반환
	}

	listNode* n = h->first; //listNode* n 에 h->first 대입
	listNode* trail = NULL; //listNode* trail를 NULL로 초기화

	/* key瑜� 湲곗��쇰줈 �쎌엯�� �꾩튂瑜� 李얜뒗�� */
	while(n != NULL) { //n이 NULL이 아니라면 반복
		if(n->key == key) { //n->key가 key 값과 같다면
			/* 泥� �몃뱶 �욎そ�� �쎌엯�댁빞�� 寃쎌슦 �몄� 寃��� */
			if(n == h->first) { //n이 h->first와 같다면
				h->first = n->link; //h->first에 n->link 대입
			} else { /* 以묎컙�� 寃쎌슦嫄곕굹 留덉�留됱씤 寃쎌슦 */  //아니라면
				trail->link = n->link; //trail->link에 n->link 대입
			}
			free(n); // n 메모리 해제
			return 0; //0으로 반환
		}

		trail = n; //trail n으로 초기화
		n = n->link; //n을 n->link로 초기화
	}

	/* 李얠� 紐� �쒓꼍�� */
	printf("cannot find the node for key = %d\n", key); //cannot find the node for key = 출력
	return 0; //0으로 반환

}

/**
 * list�� 留덉�留� �몃뱶 ��젣
 */
int deleteLast(headNode* h) {

	if (h->first == NULL) //h->first가 NULL이라면
	{
		printf("nothing to delete.\n"); //nothing to delete. 출력
		return 0; //0으로 반환
	}

	listNode* n = h->first; //listNode* n에 h->first 대입
	listNode* trail = NULL; //listNode* trail을 NULL로 초기화
 
	/* �몃뱶媛� �섎굹留� �덈뒗 寃쎌슦, 利� first node == last node��  寃쎌슦 泥섎━ */
	if(n->link == NULL) { //n->link가 NULL이라면
		h->first = NULL; //h->first를 NULL로 초기화
		free(n); //n 메모리 해제
		return 0; //0으로 반환
	}

	/* 留덉�留� �몃뱶源뚯� �대룞 */
	while(n->link != NULL) { //n->link가 NULL이 아니라면 반복
		trail = n; //trail에 n 대입
		n = n->link; //n에 n->link 대입
	}

	/* n�� ��젣�섎�濡�, �댁쟾 �몃뱶�� 留곹겕 NULL 泥섎━ */
	trail->link = NULL; //trail->link NULL로 초기화
	free(n); //n의 메모리 해제

	return 0; //0으로 반환
}
/**
 * list�� 泥ル쾲吏� �몃뱶 ��젣
 */
int deleteFirst(headNode* h) {

	if (h->first == NULL) //h->first가 NULL이라면
	{
		printf("nothing to delete.\n"); //nothing to delete. 출력
		return 0; //0으로 반환
	}
	listNode* n = h->first; //listNode* n 에 h->first 대입

	h->first = n->link; //h->first에 n->link 대입
	free(n); //n 메모리 해제

	return 0; //0으로 반환
}


/**
 * 由ъ뒪�몄쓽 留곹겕瑜� ��닚�쇰줈 �� 諛곗튂
 */
int invertList(headNode* h) {


	if(h->first == NULL) { //h->first가 NULL이라면
		printf("nothing to invert...\n"); //nothing to invert... 출력
		return 0; //0으로 반환
	}
	listNode *n = h->first; //listNode *n을 h->first로 초기화
	listNode *trail = NULL; //listNode *traul을 NULL로 초기화
	listNode *middle = NULL; //listNode *middle을 NULL로 초기화

	while(n != NULL){ //n이 NULL이 아니라면 반복
		trail = middle; //trail에 middle 대입
		middle = n; //middle에 n 대입
		n = n->link; //n에 n->link 대입
		middle->link = trail; //middle->link에 trail 대입
	}

	h->first = middle; //h->first에 middle 대입

	return 0; //0으로 반환
}


void printList(headNode* h) {
	int i = 0; //정수형 변수 i 0으로 초기화
	listNode* p; //listNodde 포인터 변수 listNode* p 선언

	printf("\n---PRINT\n"); //---PRINT 출력

	if(h == NULL) { //h가 NULL이라면
		printf("Nothing to print....\n"); //Nothing to print....
		return; //0으로 반환
	}

	p = h->first; //p에 h->first 대입

	while(p != NULL) { //p가 NULL이 아니라면 반복
		printf("[ [%d]=%d ] ", i, p->key); //[ [%d]=%d ]  출력
		p = p->link; //p에 p->link 대입
		i++; //i 증가 연산자
	}

	printf("  items = %d\n", i); //  items =출력
}