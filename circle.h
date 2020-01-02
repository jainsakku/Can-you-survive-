void draw_circle(double r)
{

  double x, y, a, b;
  double h;
  double x_prev;
  double y_prev;

  h = 1-r;
  x=0;
  y=r;
  double shift = 250;
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  while(y > x)  
  {
    x_prev = x;
    y_prev = y;
    if(h<0)
    {
      x++;
      h = h + 2*x_prev + 3;
    }
    
    else
    {
      x++;
      y--;
      h = h + 2*(x_prev - y_prev) + 5;
    }
    glVertex2f(x+l2-p1, y+man_y+man_y_duck);
    
    
    glVertex2f(y+l2-p1, x+man_y+man_y_duck);
    
    
    glVertex2f(y+l2-p1, -x+man_y+man_y_duck);
    
    
    glVertex2f(x+l2-p1, -y+man_y+man_y_duck);
    
    
    glVertex2f(-x+l2-p1, -y+man_y+man_y_duck);
    
    
    glVertex2f(-y+l2-p1, -x+man_y+man_y_duck);
    
    
    glVertex2f(-y+l2-p1, x+man_y+man_y_duck);
    
    
    glVertex2f(-x+l2-p1, y+man_y+man_y_duck);
    
  }
  glEnd();
  glFlush();
}