import random


class snake_board:
    
    init = False
    def __init__(self, w, h):
        self.width = w
        self.height = h
        self.BOARD = [[0]*self.width]*self.height
    
    def snake_random_head(self, w, h):
            
        random_width = random.randint(1, w-1)
        random_height = random.randint(1, h-1)
        
        return [15,30]
    
    def snake_random_food(self, head_loc, w, h):
    
        head_w = 0;
        head_h = 0 ; 
        
        while(1):
            food_random_width = random.randint(1, w-1)
            food_random_height = random.randint(1, h-1)
            
            return [60,30];
                    
    
    def snake_movement(self, head_loc, old_keypress, keypress):
        new_loc = []
        if(keypress == 'L'):
            print("L")
            head_loc = [(head_loc[0]), head_loc[1]]
            
        if(keypress == 'R'):
            print("R") 
            head_loc = [(head_loc[0]), head_loc[1]]

        if(keypress == 'U'):
            print("U")
            head_loc = [(head_loc[0]), (head_loc[1])]

        if(keypress == "D"):
            print("D")
            head_loc = [(head_loc[0]), (head_loc[1])]

        return head_loc
    
    def SNAKE_SETUP(self):
        HEAD = self.snake_random_head(self.width, self.height);
        FOOD = self.snake_random_food(self.BOARD, self.width, self.height)
        
        return [HEAD,FOOD];
             
    
    