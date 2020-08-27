/**
     * Bird class to represent the position of the bird.
     * Represented by a single LED on the microbit display
     */
class Bird
{
public:
  int x;
  int y;
  Bird(int x, int y); //Constructor
  void moveUp();
  void moveDown();
};

/**
     * Constructor
     * @param x - x position of the bird.
     * @param y - y position of the bird.
     * @return Void
     */
Bird::Bird(int x, int y)
{
  this->x = x;
  this->y = y;
}

/**
     * Move bird up by one LED, if the bird is currently not in the row
     * @return Void
     */
void Bird::moveUp()
{
  if (this->y > 0) //Check is the bird is currently in the top row
  {
    this->y--;
  }
}

/**
     * Move bird down by one LED, if the bird is currently not in bottom row
     * @return Void
     */
void Bird::moveDown()
{
  if (this->y < 4) //Check is the bird is currently in the bottom row
  {
    this->y++;
  }
}

void (Bird::*movebirdup)(void) = &Bird::moveUp;
void (Bird::*movebirddown)(void) = &Bird::moveDown;
