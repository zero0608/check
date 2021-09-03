#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	neu gt cua i > 90: 
	+ x = i - 65;
	+ y = (int) x / 26;
	+ i = i - (y * 26);
	
	(gia tri cua i =  gt goc + n * 26  va gia tri nho nhat la 65 => i = 65 + t + y * 26
	=> 65 + t = i - y * 26 ; dat x = t + y * 26 => x = i - 65 => y = (int) x / 26 => 65 + t = i - y * 26;
	
	#MA HOA : S + KEY - 26Y >= 65  
	#GIAI MA: S + 26Y - KEY >= 65
	// S + Y*26 - KEY >= 65 -> Y >= (65 + KEY - S) / 26
*/

int key, select;
float cs1;
int cs2;
char text[100];
int cpytext[100];//VOI KEY VERY BIG -> KIEU CHAR KHONG CHUA DUOC -> INT
char source, des;

char key_vg[100];
int TABLE[26][26];

int XAC_DINH_KEY();
void MA_HOA();
void GIAI_MA();

void CREATE_TABLE();
void show_table();
void paste_key();
void MA_HOA_VG();
void GIAI_MA_VG();


int main()
{
	int select2;
	CREATE_TABLE();
	do
	{
		printf("\n1.MA HOA CAESAR\n2.MA HOA VIGENERE\n0.THOAT\n");
		scanf("%d", &select);
		system("cls");
		
		switch(select)
		{
			case 1:
					do
					{
						printf("\n===MA HOA CAESAR===\n1.MA HOA \n2.GIAI MA\n0.THOAT\n");
						scanf("%d", &select2);
						system("cls");
						
						switch(select2)
						{
							case 1:
									printf("===MA HOA===\n");
									MA_HOA();
								break;
								
							case 2:
									printf("===GIAI MA===\n");
									GIAI_MA();
								break;	
						}
					}while(select2 != 0);
				break;
				
			case 2:
					do
					{
						printf("\n===MA HOA VIGENERE===\n1.MA HOA\n2.GIAI MA\n0.THOAT\n");
						scanf("%d", &select2);
						system("cls");
						
						switch(select2)
						{
							case 1:
									printf("===MA HOA===\n");
									show_table();
									MA_HOA_VG();
								break;
								
							case 2:
									printf("===GIAI MA===\n");
									show_table();
									GIAI_MA_VG();
								break;	
						}
					}
					while(select2 != 0);
				break;
		}
	}while(select != 0);
}

int XAC_DINH_KEY()
{
	printf("INPUT: ");
	fflush(stdin);
	source = getche();
	printf("\n");
	printf("OUTPUT: ");
	fflush(stdin);
	des = getche();
	printf("\n");
	if(des - source > 0) return (int)des - source;
	return (int)(des - source) + 26;
}

void MA_HOA()
{
	//MA HOA : S + KEY - 26 * Y >= 65  -> Y = (S + KEY - 65) / 26
	//GIAI MA: S + 26 * Y - KEY >= 65 -> S + Y*26 - KEY >= 65 -> Y >= (65 + KEY - S) / 26
	
	int i;
	//NHAP KEY:
	printf("1.NHAP KEY BANG SO\n2.NHAP INPUT , OUTPUT\n");
	do
	{
		scanf("%d", &select);
	}while(select < 1 || select > 2);
	
	if(select == 1) 
	{
		printf("NHAP KEY VAO: ");
		scanf("%d", &key);
	}
	else
	{
		key = XAC_DINH_KEY();
	}
	//NHAP CHUOI
	printf("NHAP CHUOI: ");
	fflush(stdin);
	gets(text);
	strupr(text);
	
	//COPY CHUOI TEXT VAO MANG INT CPYTEXT
	for(i = 0; i < strlen(text); ++i)
	{
		cpytext[i] = text[i];
	}
	
	//DUYET TU DAU DEN CUOI MANG
	for(i = 0; i < strlen(text); ++i)
	{
		//CHI XET NHUNG PHAN TU KHAC KHOANG TRANG
		if(cpytext[i] != 32)
		{
			cs2 = (cpytext[i] + key - 65) / 26;
			cpytext[i] = cpytext[i] + key - cs2 * 26;
		}
	}
	
	printf("\n");
	for(i = 0; i < strlen(text); ++i)
	{
		printf("%c ", cpytext[i]);
	}
}
void GIAI_MA()
{
	//MA HOA : S + KEY - 26 * Y >= 65  -> Y = (S + KEY - 65) / 26
	//GIAI MA: S + 26 * Y - KEY >= 65 -> S + Y*26 - KEY >= 65 -> Y >= (65 + KEY - S) / 26
	
	int i;
	//NHAP KEY:
	printf("1.NHAP KEY BANG SO\n2.NHAP INPUT , OUTPUT\n");
	do
	{
		scanf("%d", &select);
	}while(select < 1 || select > 2);
	
	if(select == 1) 
	{
		printf("NHAP KEY VAO: ");
		scanf("%d", &key);
	}
	else
	{
		key = XAC_DINH_KEY();
	}
	//NHAP CHUOI
	printf("NHAP CHUOI: ");
	fflush(stdin);
	gets(text);
	strupr(text);
	
	//COPY CHUOI TEXT VAO MANG INT CPYTEXT
	for(i = 0; i < strlen(text); ++i)
	{
		cpytext[i] = text[i];
	}
	
	//DUYET TU DAU DEN CUOI MANG
	for(i = 0; i < strlen(text); ++i)
	{
		//CHI XET NHUNG PHAN TU KHAC KHOANG TRANG
		if(cpytext[i] != 32)
		{
			cs1 = (float)(65 + key - cpytext[i]) / 26;//lay kieu thuc de xet truong hop khong nguyen
			cs2 = cs1;//lay phan nguyen cua gia tri y vua tinh
			cs2 = (cs1 > cs2) ? cs2 + 1 : cs2;//neu y > phan nguyen cua no -> khong nguyen -> phan nguyen + 1
			cpytext[i] = cpytext[i] + cs2 * 26 - key;
		}
	}
	
	printf("\n");
	for(i = 0; i < strlen(text); ++i)
	{
		printf("%c ", cpytext[i]);
	}
}

void CREATE_TABLE()
{
	int i, j;
	for(i = 0; i < 26; ++i)
	{
		TABLE[i][0] = i + 65;//KHOI TAO GIA TRI DAU DONG
		for(j = 1; j < 26; ++j)
		{
			TABLE[i][j] = TABLE[i][j- 1] + 1;//COT SAU = COT TRUOC + 1
			if(TABLE[i][j] == 91) TABLE[i][j] = 65;//NEU GIA TRI CUA 1 COT == 91 THI GAN LAI GIA TRI = 65
		}
	}
}

void show_table()
{
	int i, j;
	for(i = 0; i < 26; ++i)
	{
		for(j = 0; j < 26; ++j)
		{
			printf("%c ", TABLE[i][j]);
		}
		printf("\n");
	}
}

void paste_key()
{
	char cpykey[100];//CHUOI COPY
	int i;
	int nguyen = (strlen(text) - strlen(key_vg)) / strlen(key_vg);//XAC DINH CO THE NOI TIEP BAO NHIEU CHUOI KEY VAO CHINH NO( DO DAI = TEXT)
	int du = (strlen(text) - strlen(key_vg)) % strlen(key_vg);//XAC DINH CO THE NOI BAO NHIEU KI TU TU CHUOI KEY VAO CHINH NO
	
	//puts(key);
	strcpy(cpykey, key_vg);//COPY CHUOI KEY VAO CHUOI CPYKEY
	for(i = 0; i < nguyen; ++i)
	{
		strcat(key_vg, cpykey);//NOI CPY KEY VAO KEY 'NGUYEN' LAN
	}
	strncat(key_vg, cpykey, du);//NOI 'DU' KI TU CUA CPYKEY VAO KEY
	//puts(key);
}

void MA_HOA_VG()
{
	char output[100];

	printf("NHAP KEY: ");
	fflush(stdin);
	gets(key_vg);
	strupr(key_vg);
	
	printf("NHAP CHUOI: ");
	fflush(stdin);
	gets(text);
	strupr(text);
	strcpy(output, text);
	
	paste_key();//DAN KEY THEO DO DAI CUA CHUOI TEXT NHAP VAO
	
	int i;
	int x, y; //TOA DO
	for(i = 0; i < strlen(text); ++i)
	{
		if(text[i] != 32 && (text[i] < 48 || text[i] > 57))
		{
			//key: row; text: col
			x = key_vg[i] - 65;//A <=> 0, A:65 -> x = 0 -> x = A - 65; B, C...
			y = text[i] - 65;
			output[i] = TABLE[x][y];
		}
		else output[i] = text[i];
	}
	
	printf("\nCHUOI SAU KHI MA HOA:	");
	printf("%s",output);
	
}

void GIAI_MA_VG()
{
	char output[100];

	printf("NHAP KEY: ");
	fflush(stdin);
	gets(key_vg);
	strupr(key_vg);
	
	printf("NHAP CHUOI: ");
	fflush(stdin);
	gets(text);
	strupr(text);
	strcpy(output, text);
	
	paste_key();//DAN KEY THEO DO DAI CUA CHUOI TEXT NHAP VAO
	
	int i, j;
	int x, y; //TOA DO
	for(i = 0; i < strlen(text); ++i)
	{
		if(text[i] != 32 && (text[i] < 48 || text[i] > 57))//KHAC DAU CACH VA SO
		{
			x = key_vg[i] - 65;
			//KIEM TRA TAI HANG X , COT NAO CO == TEXT[I] -> Y = COT;
			for(j = 0; j < 26; ++j)
			{
				if(TABLE[x][j] == text[i])
				{
					y = j;
					break;
				}
			}
			output[i] = y + 65;//KI TU GOC = CHI SO COT + 65
		}
		else output[i] = text[i];
	}
	printf("\nCHUOI SAU KHI GIAI MA: ");
	printf("%s",output);
}
