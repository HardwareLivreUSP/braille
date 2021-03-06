# -*- coding: utf-8 -*-

"""
	Enumeração do simbolo:
	0 3
	1 4
	2 5
"""

braille = dict([
        ('1',[1,0,0,0,0,0]),
        ('2',[1,1,0,0,0,0]),
        ('3',[1,0,0,1,0,0]),
        ('4',[1,0,0,1,1,0]),
        ('5',[1,0,0,0,1,0]),
        ('6',[1,1,0,1,0,0]),
        ('7',[1,1,0,1,1,0]),
        ('8',[1,1,0,0,1,0]),
        ('9',[0,1,0,1,0,0]),
        ('0',[0,1,0,1,1,0]),
        
        ('a',[1,0,0,0,0,0]),
        ('b',[1,1,0,0,0,0]),
        ('c',[1,0,0,1,0,0]),
        ('d',[1,0,0,1,1,0]),
        ('e',[1,0,0,0,1,0]),
        ('f',[1,1,0,1,0,0]),
        ('g',[1,1,0,1,1,0]),
        ('h',[1,1,0,0,1,0]),
        ('i',[0,1,0,1,0,0]),
        ('j',[0,1,0,1,1,0]),
        ('k',[1,0,1,0,0,0]),
        ('l',[1,1,1,0,0,0]),
        ('m',[1,0,1,1,0,0]),
        ('n',[1,0,1,1,1,0]),
        ('o',[1,0,1,0,1,0]),
        ('p',[1,1,1,1,0,0]),
        ('q',[1,1,1,1,1,0]),
        ('r',[1,1,1,0,1,0]),
        
        ('s',[0,1,1,1,0,0]),
        ('t',[0,1,1,1,1,0]),
        ('u',[1,0,1,0,0,1]),
        ('v',[1,1,1,0,0,1]),
        ('w',[0,1,0,1,1,1]),
        ('x',[1,0,1,1,0,1]),
        ('y',[1,0,1,1,1,1]),
        ('z',[1,0,1,0,1,1]),
        
        ('ç',[1,1,1,1,0,1]),
        
        ('á',[1,1,1,0,1,1]),
        ('é',[1,1,1,1,1,1]),
        ('í',[0,0,1,1,0,0]),
        ('ó',[0,0,1,1,0,1]),
        ('ú',[0,1,1,1,1,1]),
        
        ('à',[1,1,0,1,0,1]),
        ('è',[0,1,1,1,0,1]),
        ('ì',[1,0,0,1,0,1]),
        ('ù',[1,0,0,0,1,1]),
        
        ('â',[1,0,0,0,0,1]),
        ('ê',[1,1,0,0,0,1]),
        ('ô',[1,0,0,1,1,1]),
        
        ('ã',[0,0,1,1,1,0]),
        ('õ',[0,1,0,1,0,1]),
        
        ('ï',[1,1,0,1,1,1]),
        ('ü',[1,1,0,0,1,1]),
        
        ('.',[0,0,1,0,0,0]),
        (',',[0,1,0,0,0,0]),
        ('?',[0,1,0,0,0,1]),
        ('!',[0,1,1,0,1,0]),
        
        ('+',[0,1,1,0,1,0]),
        ('-',[0,0,1,0,0,1]),
        ('*',[0,0,1,0,1,0]),
        ('/',[0,0,1,1,0,0]),
        ('=',[0,1,1,0,1,1]),
        ('>',[1,0,1,0,1,0]),
        ('<',[0,1,0,1,0,1]),
        
        (':',[0,1,0,0,1,0]),
        (';',[0,1,1,0,0,0]),
        
        ('(',[1,1,0,0,0,1]),
        (')',[0,0,1,1,1,0]),
        ('[',[1,1,1,0,1,1]),
        (']',[0,1,1,1,1,1]),
        
        ('"',[0,1,1,0,0,1]),
        
        ('$',[0,0,0,0,1,1]),
        ('@',[1,0,0,0,1,1]),
        ('#',[0,0,1,1,1,1]),
        ('°',[0,0,1,0,1,1]),
        (' ',[0,0,0,0,0,0])
        
        ])
        
'''
novo paragrafo = 2 digitos vazios
_ = --
4, 5, 6/3, 5, 6 
'''

def TextToBraille(t):
    """
    string --> list
    recebe um texto e devolve uma lista onde cada elemento é um caractere braile
    """
    
    LastCharDigit = False
    r = [] #texto após a conversão
    for i in t:
        if(i.isupper()):
            r.append([0, 0, 0, 1, 0, 1]) #sinal de maiuscula
            i = i.lower()
            
        if(i.isdigit() and LastCharDigit == False):
            r.append(braille['#'])
            LastCharDigit = True
        else:
            LastCharDigit = False
            
        r.append(braille[i])
        
    return r

def printBeautiful(b):
    char_to_matrix = lambda c: tuple(zip(c[0:3], c[3:6]))
    matrix_matrix = list(map(char_to_matrix, b))

    for row in range(3):
        for m in matrix_matrix:
            print(' '.join(('•' if dot == 1 else ' ') for dot in m[row]),
            end='  ')
        print()
            
def main():
    a = input("Insira um texto: ")
    
    texto = TextToBraille(a)
    printBeautiful(texto)

if __name__ == '__main__': main()
