                                                                            
;    Filename: CALCULADORA                                                                 *
;    Date:05/06/2020                                                                     *
;    File Version: 1.2                                                            *
;    Author:Miguel Falcao,Lucas Souza                                                                   *
;    Company:                                                                  *
;    Description:                                                              *
;                                                                              *
    #include "p16f877a.inc"
    #INCLUDE"CALCULATOR_DISPLAY_HEADER.inc"
    #INCLUDE"CALCULATOR_KEYBOARD_HEADER.inc"
    #INCLUDE"CALCULATOR_OPERATION_HEADER.inc"
 
; __config 0x3F3A
 __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_OFF & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF
 
GPR_VAR        UDATA
POG_VARIAVEIS 	
MILHAR	            RES	    1;
CENTENA		    RES	    1;
DEZENA		    RES	    1;
UNIDADE		    RES	    1;
INPUT_VAL	    RES	    1;VARIAVEL DE INPUT		    
INPUT_D1	    RES	    1;ENTRADA DEZENA 1	    	    	    
INPUT_U1	    RES	    1;ENTRADA UNIDADE 1 
INPUT_D2	    RES	    1;ENTRADA DEZENA 1	    	    	    
INPUT_U2	    RES	    1;ENTRADA UNIDADE 1 	    
	    
	     
RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program


ISR       CODE    0x0004
       
RETFIE
       
 
     
ENABLE_DELAYS;HABILITA DELAYS       
ENABLE_DISPLAY;HABILITA O DISPLAY       
USE_DISPLAY;HABILITA OS PRINTS NO DISPLAY
SHOW_ALL_DISPLAYS MILHAR,CENTENA,DEZENA,UNIDADE ;PASSO AS QUATRO VARIAVEIS PRA MACRO  
ENABLE_KEYBOARD     
INPUT_KEYBOARD INPUT_VAL           
OPERATIONS INPUT_U1,INPUT_D1,INPUT_U2,INPUT_D2       
;SELECT_OPERATOR SOMA,SUBTRACAO,MULTIPLICACAO
       
MAIN_PROG CODE   
 ; let linker place main program
START
 
INICIALIZA_CASAS UNIDADE,DEZENA,CENTENA,MILHAR ;INICIALIZA AS CASAS DECIMAIS COM 0
 
 
CALL CONFIG_KEYBOARD 
;LENDO PARA A DEZENA  
CALL INPUT_LOOP
MOVF INPUT_VAL, 0
MOVWF INPUT_D1
 
;LENDO PARA A UNIDADE  
CALL INPUT_LOOP
MOVF INPUT_VAL, 0
MOVWF INPUT_U1 

;SEGUNDA PARTE DO CODIGO, LENDO PARA O SEGUNDO NUMERO A SER OPERADO 
;CODIGO REPETIDO
CALL INPUT_LOOP
MOVF INPUT_VAL, 0
MOVWF INPUT_D2
 
CALL INPUT_LOOP
MOVF INPUT_VAL, 0
MOVWF INPUT_U2 
CALL WAIT_OPERATOR 
RESULTADO: 
CALL CONFIG_DISPLAY 
LOOP
    CALL SHOW_NUMBERS
GOTO LOOP


    

 WAIT_OPERATOR:
    ;operacao de soma
    BCF PORTB, RB2
    CALL DELAY_1MS
    CALL DELAY_1MS ;ESSE DELAY AQUI NAO FAZ O MENOR SENTIDO, MAS SE TIRAR BUGA
    BTFSS TRISD, RD0
    GOTO SOMA;OPERATOR_1    
    CALL DELAY_1MS
    CALL DELAY_1MS
    BSF PORTB, RB2
    
    ;operacao de subtracao
    BCF PORTB, RB1
    CALL DELAY_1MS
    CALL DELAY_1MS ;ESSE DELAY AQUI NAO FAZ O MENOR SENTIDO, MAS SE TIRAR BUGA
    BTFSS TRISD, RD0 ;0
    GOTO SUBTRACAO;OPERATOR_2 
    CALL DELAY_1MS
    CALL DELAY_1MS
    BSF PORTB, RB1
    
    ;operacao de multiplicacao
    BCF PORTB, RB0
    CALL DELAY_1MS
    CALL DELAY_1MS ;ESSE DELAY AQUI NAO FAZ O MENOR SENTIDO, MAS SE TIRAR BUGA
    BTFSS TRISD, RD0 ; *
    GOTO MULTIPLICACAO;OPERATOR_3 11 * 11 = 121
    CALL DELAY_1MS
    CALL DELAY_1MS
    BSF PORTB, RB0    
    
    GOTO WAIT_OPERATOR
    
    
SOMA: ; 11 + 11  = 22
    CALL OPERATOR_SOMA
    GOTO RESULTADO
SUBTRACAO: ; 56 - 55 = 01
    CALL OPERATOR_SUB
    GOTO RESULTADO
MULTIPLICACAO: ; 44 * 20 = 
    CALL OPERATOR_MULTI
    GOTO RESULTADO
    
    
 
    END