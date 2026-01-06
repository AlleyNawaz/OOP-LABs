import pygame
import math

# --- CONFIGURATION ---
WIDTH, HEIGHT = 800, 600
FPS = 60
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 50, 50)
GREEN = (50, 255, 50)
BLUE = (50, 50, 255)
YELLOW = (255, 255, 0)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("THAPPAR LEGENDS: The Prototype")
clock = pygame.time.Clock()
font = pygame.font.SysFont("comicsansms", 30)
big_font = pygame.font.SysFont("comicsansms", 60)

class Player:
    def __init__(self, x, color, name):
        self.x = x
        self.y = HEIGHT // 2
        self.color = color
        self.name = name
        self.health = 100
        self.is_stunned = False
        self.face_color = color
    
    def draw(self, screen):
        # Draw Body
        pygame.draw.rect(screen, self.color, (self.x, self.y, 100, 150))
        # Draw Head
        pygame.draw.circle(screen, self.face_color, (self.x + 50, self.y - 30), 40)
        # Draw Name
        name_text = font.render(self.name, True, BLACK)
        screen.blit(name_text, (self.x, self.y - 80))
        # Draw Health Bar
        pygame.draw.rect(screen, RED, (self.x, self.y + 160, 100, 10))
        pygame.draw.rect(screen, GREEN, (self.x, self.y + 160, self.health, 10))

    def take_slap(self, damage):
        self.health -= damage
        self.face_color = RED # Face turns red from slap
        if self.health < 0: self.health = 0

    def recover(self):
        self.face_color = self.color

class SlapMeter:
    def __init__(self):
        self.width = 400
        self.height = 30
        self.x = (WIDTH - self.width) // 2
        self.y = 100
        self.cursor_pos = 0
        self.direction = 1
        self.speed = 10
        self.moving = True
        self.target_zone_start = 180
        self.target_zone_end = 220 # The "Sweet Spot" in the middle

    def update(self):
        if self.moving:
            self.cursor_pos += self.speed * self.direction
            # Bounce back and forth
            if self.cursor_pos >= self.width or self.cursor_pos <= 0:
                self.direction *= -1

    def draw(self, screen):
        # Draw container
        pygame.draw.rect(screen, BLACK, (self.x - 5, self.y - 5, self.width + 10, self.height + 10))
        pygame.draw.rect(screen, WHITE, (self.x, self.y, self.width, self.height))
        
        # Draw Target Zone (The Green Area)
        pygame.draw.rect(screen, GREEN, (self.x + self.target_zone_start, self.y, 
                                         self.target_zone_end - self.target_zone_start, self.height))
        
        # Draw Cursor
        pygame.draw.rect(screen, RED, (self.x + self.cursor_pos, self.y - 10, 5, self.height + 20))

    def stop(self):
        self.moving = False
        # Calculate score based on distance to center
        center = (self.target_zone_end + self.target_zone_start) / 2
        distance = abs(self.cursor_pos - center)
        
        if self.target_zone_start <= self.cursor_pos <= self.target_zone_end:
            return "PERFECT"
        elif distance < 100:
            return "WEAK"
        else:
            return "MISS"
            
    def restart(self):
        self.moving = True
        self.speed += 1 # It gets faster every turn!

# --- MAIN GAME LOOP ---
def main():
    p1 = Player(100, BLUE, "Sami")
    p2 = Player(600, (200, 100, 0), "Moiz")
    meter = SlapMeter()
    
    turn = 1 # 1 for Sami, 2 for Moiz
    game_state = "AIMING" # AIMING, RESULT, GAME_OVER
    message = "Sami's Turn! Press SPACE!"
    
    running = True
    while running:
        screen.fill((240, 240, 240)) # Light Gray Background
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and game_state == "AIMING":
                    result = meter.stop()
                    game_state = "RESULT"
                    
                    if result == "PERFECT":
                        damage = 30
                        message = "CRITICAL HIT! OOF!"
                        if turn == 1: p2.take_slap(damage)
                        else: p1.take_slap(damage)
                    elif result == "WEAK":
                        damage = 10
                        message = "Weak Slap..."
                        if turn == 1: p2.take_slap(damage)
                        else: p1.take_slap(damage)
                    else:
                        message = "YOU MISSED! LOL!"
                    
                elif event.key == pygame.K_SPACE and game_state == "RESULT":
                    if p1.health == 0 or p2.health == 0:
                        # Reset game
                        p1.health = 100
                        p2.health = 100
                        meter.speed = 10
                    else:
                        # Next Turn
                        turn = 2 if turn == 1 else 1
                        p1.recover()
                        p2.recover()
                        meter.restart()
                        game_state = "AIMING"
                        message = f"{'Sami' if turn == 1 else 'Moiz'}'s Turn!"

        # Updates
        if game_state == "AIMING":
            meter.update()

        # Drawing
        p1.draw(screen)
        p2.draw(screen)
        meter.draw(screen)
        
        # Draw UI Text
        text = font.render(message, True, BLACK)
        screen.blit(text, (WIDTH//2 - text.get_width()//2, 500))

        if p1.health <= 0:
            win_text = big_font.render("MOIZ WINS!", True, RED)
            screen.blit(win_text, (WIDTH//2 - win_text.get_width()//2, HEIGHT//2))
            game_state = "RESULT"
        elif p2.health <= 0:
            win_text = big_font.render("SAMI WINS!", True, BLUE)
            screen.blit(win_text, (WIDTH//2 - win_text.get_width()//2, HEIGHT//2))
            game_state = "RESULT"

        pygame.display.flip()
        clock.tick(FPS)

    pygame.quit()

if __name__ == "__main__":
    main()