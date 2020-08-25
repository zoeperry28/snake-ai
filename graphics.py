from snake_logic import snake_board
import pygame
# define a main function

multiplier = 10 
red = (255,0,0)
blue = (0,0,255)
green = (0,255,0)
lol = (255,255,0)
white = (255,255,255)
black = (0,0,0)
def main():
    
    print("hello")
    s = snake_board(100,100);
    TO_REPLICATE = s.SNAKE_SETUP()
    
    init = False;
    for r in TO_REPLICATE:
        for c in r:
            print(c,end = " ")
    print("LOL")
    windw(init, s.BOARD, s.width*multiplier, s.height*multiplier, TO_REPLICATE) 

def use_data(screen, BOARD, width, height, coords, old_keypress, mv, food_loc, food_score):
    
    new_i = 0;
    new_j = 0;
    
    HEAD_LOC = [] 
    sb = snake_board(0,0);
                
    for i in range(len(BOARD)):
        for j in range(len(BOARD[i])):

            if(((i == len(BOARD)-1) or (j == len(BOARD[i])-1)) or ((i == 0) or (j == 0))) :
                pygame.draw.rect(screen, red, (i*multiplier, j*multiplier, 10,10))  
            else: 
                pygame.draw.rect(screen, white, (i*multiplier, j*multiplier, 10,10))     

    xy = movement_graphics(screen, BOARD, coords, old_keypress, mv, 0)
    return xy;
    
def movement_graphics(screen, board, coords, oDirection, nDirection, food_score): 
    INIT_X = coords[0][0]
    INIT_Y = coords[0][1]
    count = 0
    if(nDirection == 'U'):
        INIT_Y = INIT_Y - 1
        count = food_score+3
        for i in range(1,count):
            pygame.draw.rect(screen, blue, (INIT_X*multiplier, (INIT_Y+i)*multiplier, 10,10)) 
    if(nDirection == 'D'):
        INIT_Y = INIT_Y + 1
        count = food_score+3
        for i in range(1,count):
            pygame.draw.rect(screen, blue, (INIT_X*multiplier, (INIT_Y-i)*multiplier, 10,10)) 
            
    if(nDirection == 'L'):
        INIT_X = INIT_X - 1
        count = food_score+3
        for i in range(1,count):
            pygame.draw.rect(screen, blue, ((INIT_X+i)*multiplier, INIT_Y*multiplier, 10,10)) 
            
    if(nDirection == 'R'):
        INIT_X = INIT_X + 1
        count = food_score+3
        for i in range(1,count):
            pygame.draw.rect(screen, blue, ((INIT_X-i)*multiplier, INIT_Y*multiplier, 10,10)) 
            
    pygame.draw.rect(screen, red, (INIT_X*multiplier, INIT_Y*multiplier, 10,10)) 
    
     
    return [[INIT_X,INIT_Y]]
                        
def windw(init, BOARD, width, height, TO_REPLICATE) :
    
    # initialize the pygame module
    pygame.init()
    # load and set the logo
    pygame.display.set_caption("minimal program")
     
    # create a surface on screen that has the size of 240 x 180
    screen = pygame.display.set_mode((width,height))
    screen.fill(white)
    
    # define a variable to control the main loop
    running = True
    mv = '0'
    prev_ins = 0 
    oldk = '2'
    incr = 0 
    DAT = 0 
    while running:
        
        
        # event handling, gets all event from the event queue
        for event in pygame.event.get():
            # only do something if the event is of type QUIT
            if event.type == pygame.QUIT:
                # change the value to False, to exit the main loop
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    mv = 'L'
                if event.key == pygame.K_RIGHT:
                    mv = 'R'
                if event.key == pygame.K_UP:
                    mv = 'U'
                if event.key == pygame.K_DOWN:
                    mv = 'D' 
                    
        if(incr == 0):
            DAT  = use_data(screen, BOARD, width, height, TO_REPLICATE, oldk, mv)
            incr += 1
        else:
            DAT = use_data(screen, BOARD, width, height, DAT, oldk, mv)
        pygame.display.update()
        oldk=mv
            
    
main()