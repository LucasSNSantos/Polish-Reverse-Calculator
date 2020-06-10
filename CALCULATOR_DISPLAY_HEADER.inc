#IFNDEF CALCULATOR_DISPLAY_HEADER
#DEFINE CALCULATOR_DISPLAY_HEADER
#INCLUDE"GENERAL_USE_HEADER.inc"    
    
;VALORES PARA O DISPLAY 
DISPLAY_3	 EQU  B'00001000' ;DISPLAY 2
DISPLAY_4	 EQU  B'00010000' ;DISPLAY 3	 
DISPLAY_2	 EQU  B'00000100' ;DISPLAY 1
DISPLAY_1	 EQU  B'00100000' ;DISPLAY 4
 
;VALORES NUMERICOS DO DISPLAY
ZERO	 EQU  B'00111111'	   	 
UM	 EQU  B'00000110'
DOIS	 EQU  B'01011011'
TRES	 EQU  B'01001111'
QUATRO	 EQU  B'01100110'
CINCO	 EQU  B'01101101'
SEIS	 EQU  B'01111101'
SETE	 EQU  B'00100111'
OITO	 EQU  B'01111111'
NOVE	 EQU  B'01100111'
	 
	 	 
ENABLE_DISPLAY MACRO
;CONFIGURA O DISPLAY PRA SAIDA DE DADOS 
CONFIG_DISPLAY:
    BANK1
    MOVLW   B'00001000'
    MOVWF   TRISB
    CLRF    TRISD
    CLRF    TRISA
    BANK0
    CLRF PORTB 
    CLRF PORTD
    RETURN 
    
;ATIVA O DISPLAY 1    
ATIVA_DISPLAY_1:
    MOVLW DISPLAY_1
    MOVWF PORTA
    RETURN
;ATIVA O DISPLAY 2    
ATIVA_DISPLAY_2:
    MOVLW DISPLAY_2
    MOVWF PORTA
    RETURN    
;ATIVA O DISPLAY 3    
ATIVA_DISPLAY_3:
    MOVLW DISPLAY_3
    MOVWF PORTA
    RETURN
;ATIVA O DISPLAY 4    
ATIVA_DISPLAY_4:
    MOVLW DISPLAY_4
    MOVWF PORTA
    RETURN   
    
    ENDM
    
USE_DISPLAY MACRO 
;PRINTS DO DISPLAY 
PRINT_0:
    MOVLW ZERO ;0
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_1:
    MOVLW UM ;1
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_2:   
    MOVLW DOIS ;2
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_3:
    MOVLW TRES ;3
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_4:
    MOVLW QUATRO ;4
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_5:
    MOVLW CINCO ;5
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;;CALL DELAY_1MS
    RETURN 
PRINT_6:
    MOVLW SEIS ;6
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_7:
    MOVLW SETE ;7
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_8:
    MOVLW OITO ;8
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN 
PRINT_9:
    MOVLW NOVE ;9
    MOVWF PORTD
    ;CALL DELAY_1MS
    ;CALL DELAY_1MS
    RETURN
    
    ENDM 
    
;MOSTRA O VALOR     
SHOW_ALL_DISPLAYS MACRO MILHAR,CENTENA,DEZENA,UNIDADE
 
SHOW_NUMBERS:
    ;MOSTRAR O VALOR DO MILHAR
    CALL ATIVA_DISPLAY_1
    ;COMPARANDO O MILHAR COM O NUMERO PARA PRINTAR NO DISPLAY
    CMP MILHAR, D'9', TRUE_MILHAR_9, FALSE_MILHAR_8
FALSE_MILHAR_8:
    CMP MILHAR, D'8', TRUE_MILHAR_8, FALSE_MILHAR_7
FALSE_MILHAR_7:
    CMP MILHAR, D'7', TRUE_MILHAR_7, FALSE_MILHAR_6
FALSE_MILHAR_6:
    CMP MILHAR, D'6', TRUE_MILHAR_6, FALSE_MILHAR_5
FALSE_MILHAR_5:
    CMP MILHAR, D'5', TRUE_MILHAR_5, FALSE_MILHAR_4
FALSE_MILHAR_4:
    CMP MILHAR, D'4', TRUE_MILHAR_4, FALSE_MILHAR_3
FALSE_MILHAR_3:
    CMP MILHAR, D'3', TRUE_MILHAR_3, FALSE_MILHAR_2
FALSE_MILHAR_2:
    CMP MILHAR, D'2', TRUE_MILHAR_2, FALSE_MILHAR_1
FALSE_MILHAR_1:
    CMP MILHAR, D'1', TRUE_MILHAR_1, FALSE_MILHAR_0
FALSE_MILHAR_0:
    CMP MILHAR, D'0', TRUE_MILHAR_0, SHOW_CENTENA
    ;PRINTANDO OS VALORES DO MILHAR
TRUE_MILHAR_9:
    CALL PRINT_9
    GOTO SHOW_CENTENA
TRUE_MILHAR_8:
    CALL PRINT_8
    GOTO SHOW_CENTENA
TRUE_MILHAR_7:
    CALL PRINT_7
    GOTO SHOW_CENTENA
TRUE_MILHAR_6:
    CALL PRINT_6
    GOTO SHOW_CENTENA
TRUE_MILHAR_5:
    CALL PRINT_5
    GOTO SHOW_CENTENA
TRUE_MILHAR_4:
    CALL PRINT_4
    GOTO SHOW_CENTENA
TRUE_MILHAR_3:
    CALL PRINT_3
    GOTO SHOW_CENTENA
TRUE_MILHAR_2:
    CALL PRINT_2
    GOTO SHOW_CENTENA
TRUE_MILHAR_1:
    CALL PRINT_1
    GOTO SHOW_CENTENA
TRUE_MILHAR_0:
    CALL PRINT_0
    GOTO SHOW_CENTENA
   
SHOW_CENTENA:
    ;MOSTRAR O VALOR DA CENTENA
    CALL ATIVA_DISPLAY_2
    ;COMPARANDO O MILHAR COM O NUMERO PARA PRINTAR NO DISPLAY
    CMP CENTENA, D'9', TRUE_CENTENA_9, FALSE_CENTENA_8
FALSE_CENTENA_8:
    CMP CENTENA, D'8', TRUE_CENTENA_8, FALSE_CENTENA_7
FALSE_CENTENA_7:
    CMP CENTENA, D'7', TRUE_CENTENA_7, FALSE_CENTENA_6
FALSE_CENTENA_6:
    CMP CENTENA, D'6', TRUE_CENTENA_6, FALSE_CENTENA_5
FALSE_CENTENA_5:
    CMP CENTENA, D'5', TRUE_CENTENA_5, FALSE_CENTENA_4
FALSE_CENTENA_4:
    CMP CENTENA, D'4', TRUE_CENTENA_4, FALSE_CENTENA_3
FALSE_CENTENA_3:
    CMP CENTENA, D'3', TRUE_CENTENA_3, FALSE_CENTENA_2
FALSE_CENTENA_2:
    CMP CENTENA, D'2', TRUE_CENTENA_2, FALSE_CENTENA_1
FALSE_CENTENA_1:
    CMP CENTENA, D'1', TRUE_CENTENA_1, FALSE_CENTENA_0
FALSE_CENTENA_0:
    CMP CENTENA, D'0', TRUE_CENTENA_0, SHOW_DEZENA
    ;PRINTANDO OS VALORES DO MILHAR
TRUE_CENTENA_9:
    CALL PRINT_9
    GOTO SHOW_DEZENA
TRUE_CENTENA_8:
    CALL PRINT_8
    GOTO SHOW_DEZENA
TRUE_CENTENA_7:
    CALL PRINT_7
    GOTO SHOW_DEZENA
TRUE_CENTENA_6:
    CALL PRINT_6
    GOTO SHOW_DEZENA
TRUE_CENTENA_5:
    CALL PRINT_5
    GOTO SHOW_DEZENA
TRUE_CENTENA_4:
    CALL PRINT_4
    GOTO SHOW_DEZENA
TRUE_CENTENA_3:
    CALL PRINT_3
    GOTO SHOW_DEZENA
TRUE_CENTENA_2:
    CALL PRINT_2
    GOTO SHOW_DEZENA
TRUE_CENTENA_1:
    CALL PRINT_1
    GOTO SHOW_DEZENA
TRUE_CENTENA_0:
    CALL PRINT_0
    GOTO SHOW_DEZENA   
    
SHOW_DEZENA:
    ;MOSTRAR O VALOR DA CENTENA
    CALL ATIVA_DISPLAY_3
    ;COMPARANDO O MILHAR COM O NUMERO PARA PRINTAR NO DISPLAY
    CMP DEZENA, D'9', TRUE_DEZENA_9, FALSE_DEZENA_8
FALSE_DEZENA_8:
    CMP DEZENA, D'8', TRUE_DEZENA_8, FALSE_DEZENA_7
FALSE_DEZENA_7:
    CMP DEZENA, D'7', TRUE_DEZENA_7, FALSE_DEZENA_6
FALSE_DEZENA_6:
    CMP DEZENA, D'6', TRUE_DEZENA_6, FALSE_DEZENA_5
FALSE_DEZENA_5:
    CMP DEZENA, D'5', TRUE_DEZENA_5, FALSE_DEZENA_4
FALSE_DEZENA_4:
    CMP DEZENA, D'4', TRUE_DEZENA_4, FALSE_DEZENA_3
FALSE_DEZENA_3:
    CMP DEZENA, D'3', TRUE_DEZENA_3, FALSE_DEZENA_2
FALSE_DEZENA_2:
    CMP DEZENA, D'2', TRUE_DEZENA_2, FALSE_DEZENA_1
FALSE_DEZENA_1:
    CMP DEZENA, D'1', TRUE_DEZENA_1, FALSE_DEZENA_0
FALSE_DEZENA_0:
    CMP DEZENA, D'0', TRUE_DEZENA_0, SHOW_UNIDADE
    ;PRINTANDO OS VALORES DO MILHAR
TRUE_DEZENA_9:
    CALL PRINT_9
    GOTO SHOW_UNIDADE
TRUE_DEZENA_8:
    CALL PRINT_8
    GOTO SHOW_UNIDADE
TRUE_DEZENA_7:
    CALL PRINT_7
    GOTO SHOW_UNIDADE
TRUE_DEZENA_6:
    CALL PRINT_6
    GOTO SHOW_UNIDADE
TRUE_DEZENA_5:
    CALL PRINT_5
    GOTO SHOW_UNIDADE
TRUE_DEZENA_4:
    CALL PRINT_4
    GOTO SHOW_UNIDADE
TRUE_DEZENA_3:
    CALL PRINT_3
    GOTO SHOW_UNIDADE
TRUE_DEZENA_2:
    CALL PRINT_2
    GOTO SHOW_UNIDADE
TRUE_DEZENA_1:
    CALL PRINT_1
    GOTO SHOW_UNIDADE
TRUE_DEZENA_0:
    CALL PRINT_0
    GOTO SHOW_UNIDADE
 
SHOW_UNIDADE:
    ;MOSTRAR O VALOR DA CENTENA
    CALL ATIVA_DISPLAY_4
    ;COMPARANDO O MILHAR COM O NUMERO PARA PRINTAR NO DISPLAY
    CMP UNIDADE, D'9', TRUE_UNIDADE_9, FALSE_UNIDADE_8
FALSE_UNIDADE_8:
    CMP UNIDADE, D'8', TRUE_UNIDADE_8, FALSE_UNIDADE_7
FALSE_UNIDADE_7:
    CMP UNIDADE, D'7', TRUE_UNIDADE_7, FALSE_UNIDADE_6
FALSE_UNIDADE_6:
    CMP UNIDADE, D'6', TRUE_UNIDADE_6, FALSE_UNIDADE_5
FALSE_UNIDADE_5:
    CMP UNIDADE, D'5', TRUE_UNIDADE_5, FALSE_UNIDADE_4
FALSE_UNIDADE_4:
    CMP UNIDADE, D'4', TRUE_UNIDADE_4, FALSE_UNIDADE_3
FALSE_UNIDADE_3:
    CMP UNIDADE, D'3', TRUE_UNIDADE_3, FALSE_UNIDADE_2
FALSE_UNIDADE_2:
    CMP UNIDADE, D'2', TRUE_UNIDADE_2, FALSE_UNIDADE_1
FALSE_UNIDADE_1:
    CMP UNIDADE, D'1', TRUE_UNIDADE_1, FALSE_UNIDADE_0
FALSE_UNIDADE_0:
    CMP UNIDADE, D'0', TRUE_UNIDADE_0, FINAL
    ;PRINTANDO OS VALORES DO MILHAR
TRUE_UNIDADE_9:
    CALL PRINT_9
    GOTO FINAL
TRUE_UNIDADE_8:
    CALL PRINT_8
    GOTO FINAL
TRUE_UNIDADE_7:
    CALL PRINT_7
    GOTO FINAL
TRUE_UNIDADE_6:
    CALL PRINT_6
    GOTO FINAL
TRUE_UNIDADE_5:
    CALL PRINT_5
    GOTO FINAL
TRUE_UNIDADE_4:
    CALL PRINT_4
    GOTO FINAL
TRUE_UNIDADE_3:
    CALL PRINT_3
    GOTO FINAL
TRUE_UNIDADE_2:
    CALL PRINT_2
    GOTO FINAL
TRUE_UNIDADE_1:
    CALL PRINT_1
    GOTO FINAL
TRUE_UNIDADE_0:
    CALL PRINT_0
    GOTO FINAL
FINAL:
    RETURN
    
    
  ENDM 
    
    
    
    
    
    
    
    
    
#ENDIF

