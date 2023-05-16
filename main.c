#include <ncurses.h>
#include <stdlib.h>
typedef struct Room
{
    int xPos;
    int yPos;
    int height;
    int width;
} Room;
typedef struct Player
{
    int xPos;
    int yPos;
    int hp;
} Player;
int screenSetUp();
Player *playerSetUp();
Room ** mapSetUp();
int handleInput(int input, Player * user);
int playerMove(int y, int x, Player *user);
int checkPosition(int newY, int newX, Player * user);
Room * createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
int main()
{
    Player * user;
    int ch;
    screenSetUp();
    mapSetUp();
    user = playerSetUp();
    while ((ch = getch()) != 'q')
    {
        handleInput(ch, user);
    }
    endwin();
    return 0;
}

int screenSetUp()
{
    initscr();
    printw("fff");
    noecho();
    refresh();

    return 1;
}

Room ** mapSetUp()
{
    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);
    rooms[0] =  createRoom(13,13,6,8);
    drawRoom(rooms[0]);
    rooms[1] = createRoom(30,3,5,7);
    drawRoom(rooms[1]);
    rooms[2] = createRoom(40, 10, 6, 12);
    drawRoom(rooms[2]);
    return rooms;
}
Room * createRoom(int x, int y, int height, int width)
{
    Room * newRoom;
    newRoom = malloc(sizeof(Room));
    newRoom->xPos = x;
    newRoom->yPos = y;
    newRoom->height = height;
    newRoom->width = width;
    return newRoom;
}
int drawRoom(Room * room)
{
    int x;
    int y;

    for (x = room->xPos; x< room->xPos + room->width; x++){
        mvprintw(room->yPos, x,"-");
        mvprintw(room->yPos + room->height-1, x,"-");
    }
    for (y = room->yPos + 1; y< room->yPos + room->height-1; y++){
        mvprintw(y, room->xPos,"|");
        mvprintw(y, room->xPos + room->width - 1,"|");
    
        for (x = room->xPos+1; x< room->xPos + room->width-1; x++){
            mvprintw(y, x,".");
        }
    }
    return 1;
}
Player * playerSetUp()
{
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));
    playerMove(14,14, newPlayer);
    newPlayer ->hp = 20;
    mvprintw(newPlayer->yPos, newPlayer->xPos, "@");
    move(newPlayer->yPos, newPlayer->xPos);
    return newPlayer;
}
int handleInput(int input, Player * user)
{
    int newX;
    int newY;

    switch(input)
    {
        case 'w':
            newY = user->yPos - 1;
            newX = user->xPos;
            break;
        case 's':
            newY = user->yPos + 1;
            newX = user->xPos;
            break;
        case 'a':
            newY = user->yPos;
            newX = user->xPos - 1;
            break;
        case 'd':
            newY = user->yPos;
            newX = user->xPos + 1;
            break;
    }
    checkPosition(newY, newX, user);

}
int checkPosition(int newY, int newX, Player * user)
{   
    switch(mvinch(newY, newX))
    {
        case '.':
            playerMove(newY, newX, user);
            break;
        default:
            move(user->yPos, user->xPos);
            break;
    }
}
int playerMove(int y, int x, Player *user)
{
    mvprintw(user->yPos, user->xPos, ".");
    user->yPos = y;
    user ->xPos = x;
    mvprintw(user->yPos, user->xPos, "@");
    move(user->yPos, user->xPos);
}