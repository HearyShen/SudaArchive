;-----------------------------------------
;EX61
;1427405017
;沈家赟
;-----------------------------------------
;6.6   请编写程序ex61实现如下功能：
;由用户从键盘输入一个字符串（以回车符表示字符串结束）；
;然后，分别统计字符串中英文字母的个数和数字符的个数；
;最后，分别输出统计结果（十进制数形式）。
;请设计合适的子程序。	
;-----------------------------------------
	segment   ex61      ;命名段ex61
    org   100H          ;段内偏移从100H开始计算
    ;
    MOV   AX, CS
    MOV   DS, AX        ;使数据段与代码段相同
    ;
    MOV   DX, note     ;准备PUT_STR入口参数：DX=note的段内偏移
    CALL PUT_STR
    ;
	XOR DI, DI
	MOV DI, str_in
	CALL GET_STR	;键盘输入字符串
	;
	CALL NEW_LINE	;显示换行
	CALL NEW_LINE	;显示换行
	;
	MOV DX, note_str_in
	CALL PUT_STR
	MOV   DX, str_in     ;准备PUT_STR入口参数：DX=str_in的段内偏移
	CALL PUT_STR	;显示字符串，验证内存域已被输入
	CALL NEW_LINE
	
	;
	MOV SI, str_in
MAIN_LOOP:
	MOV AL, [SI]
	CMP AL, '$'
	JE END_LOOP
	CALL COUNT_ALPHABET	;[alpha_count]计数器
	CALL COUNT_NUMBER	;[num_count]计数器
	INC SI
	JMP MAIN_LOOP
END_LOOP:
	;
	CALL NEW_LINE
	;
	MOV DX, note_alphabet	;显示提示
	CALL PUT_STR
	MOV EAX, [alpha_count]
	MOV DI, alpha_count_str
	CALL CONVERT_INT_TO_STR	;十进制数值转字符串
	MOV DX, DI
	CALL PUT_STR	;显示十进制数字字符串
	CALL NEW_LINE
	;
	MOV DX, note_num	;显示提示
	CALL PUT_STR
	MOV EAX, [num_count]
	MOV DI, alpha_count_str
	CALL CONVERT_INT_TO_STR	;十进制数值转字符串
	MOV DX, DI
	CALL PUT_STR	;显示十进制数字字符串
	CALL NEW_LINE
	;
	
	MOV DX, note_exit
	CALL PUT_STR
	CALL GET_CHAR	;实现按任意键退出
    MOV   AH, 4CH
    INT   21H		;返回操作系统
;---------------------------------------
;
;子程序:GET_CHAR
;输入：等待键盘输入
;输出：AL-读取的字节（键盘输入）
;
GET_CHAR:
	MOV   AH, 1		;read a char
	INT   21H
	RET
;---------------------------------------
;
;子程序:GET_STR
;输入：DI-内存单元首地址
;输出：DI
;
GET_STR:
	CALL GET_CHAR
	CMP AL, 0DH		;detect Enter
	JE FIN_GET_STR
	
	MOV [DI], AL
	INC DI
	JMP GET_STR
FIN_GET_STR:
	; MOV DL, 0DH
	; MOV [DI], DL
	; INC DI
	; MOV DL, 0AH
	; MOV [DI], DL
	; INC DI
	MOV DL, '$'
	MOV [DI], DL
	RET
;----------------------------------------
;
;子程序:PUT_CHAR
;输入：DL-待显示的字节字符
;输出：控制台显示
;
PUT_CHAR:
	MOV   AH, 2 	;put a char
	INT   21H
	RET
;----------------------------------------
;
;子程序:PUT_STR
;输入：DS:DX-内存单元首地址
;输出：控制台显示
;注意：'$'结束字符串
;
PUT_STR:
    MOV   AH, 9
    INT   21H           ;显示DS:DX开始的字符串（以$结尾）
	RET
;----------------------------------------
;
;子程序:NEW_LINE
;输入：无
;输出：控制台显示换行
;
NEW_LINE:
	MOV AH, 2		;\r\n
	MOV DL, 0DH
	INT 21H
	MOV DL, 0AH
	INT 21H
	RET
;----------------------------------------
;
;子程序:COUNT_ALPHABET
;输入：AL-待比较值
;输出：[BX]-存储单元
;
COUNT_ALPHABET:
	CMP AL, 'A'
	JB EXCLUSION
	CMP AL, 'Z'
	JNA ALPHABET
	CMP AL, 'z'
	JA EXCLUSION
	CMP AL, 'a'
	JNB ALPHABET
	RET
ALPHABET:
	PUSH DX
	MOV DL, [alpha_count]
	INC DL
	MOV [alpha_count], DL
	POP DX
	RET
;----------------------------------------
;
;子程序:COUNT_NUMBER
;输入：AL-待比较值
;输出：[CX]-存储单元
;
COUNT_NUMBER:
	CMP AL, '0'
	JB EXCLUSION
	CMP AL, '9'
	JA EXCLUSION
	PUSH BX
	MOV BL, [num_count]
	INC BL
	MOV [num_count], BL
	POP BX
	RET
EXCLUSION:
	RET
;----------------------------------------
;
;子程序:CONVERT_INT_TO_STR
;输入：EAX-存放数值的通用寄存器
;	   EDI-存放转换结果输出地址的通用寄存器
;输出：通用寄存器EDI所指向的字符数组的值
;
CONVERT_INT_TO_STR:
	PUSH EBX;
	MOV ECX, 0;		//ECX作为入栈个数计数器，初始化置零
	MOV BX, 10;
		
DIV_PUSH:
	MOVZX EAX, AX;
	ROL EAX, 16;	//左循环移16位，使高16位位于AX
	MOV DX, AX;		//高16位从AX移入DX
	ROR EAX, 16;	//恢复

	DIV BX;			//商：AX，余数：DX
	PUSH DX;
	INC ECX;
	
	CMP AX, 0;		//商为0，则不再除，跳出除运算循环
	JE PRE_POP;
	JMP DIV_PUSH;
PRE_POP:
	MOV EBX, 0;		//EBX作为出栈个数计数器，初始化置零
POP_LOOP:
	POP DX;			//取出两字节数据
	ADD DL, '0';	//数值转字符
	MOV [EDI+EBX], DL;	//将有效的低字节部分移入主存中的输出数组
	INC EBX;		//计数器加1
	
	CMP EBX, ECX;
	JE POP_END;
	JMP POP_LOOP;
POP_END:
	MOV DL, '$'
	MOV [EDI+EBX], DL;	//字符数组结尾须补'$'
	POP EBX;
	RET;
;----------------------------------------
;
note db "EX61_1427405017_JiayunShen",0DH,0AH,"Please Enter a string:",0DH,0AH,'$'     ;定义字符串信息-初始化信息
note_str_in db "Memery str_in:",0DH,0AH,'$'     ;定义字符串信息-提示存储单元内容
note_alphabet db "alpha_count:",0DH,0AH,'$'     ;定义字符串信息-提示字母个数
note_num db "num_count:",0DH,0AH,'$'     ;定义字符串信息-提示数字个数
note_exit db "Press any key to exit.",0DH,0AH,'$'	;定义字符串信息-提示按任意键退出

str_in resb 100		; 预留100字节输入字符串空间
alpha_count resd 1		; 预留1双字alpha_count单元
alpha_count_str resb 10 ; 预留10字节作十进制显示字符串
num_count resd 1		; 预留1双字num_count单元
num_count_str resb 10 ; 预留10字节作十进制显示字符串