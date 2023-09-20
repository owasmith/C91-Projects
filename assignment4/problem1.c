#include <stdio.h>
int calculateRectArea(int length, int width);
int calculateTriArea(int length, int width);

int rectArea;
int triArea;


int main()
{
	int length;
	int width;
	printf("This is a program to calculate the area of a rectangle and a triangle. \n");
	printf("Please enter a length: \n");
	scanf("%d", &length);

	printf("Please enter a width: \n");
	scanf("%d", &width);

	triArea = calculateTriArea(length, width);

	printf("Rectangle Area: %d\nTriangle Area: %d\n", rectArea, triArea);

}

int calculateTriArea(int length, int width)
{
	int area = .5 * calculateRectArea(length, width);
	return area;
}

int calculateRectArea(int length, int width)
{
	rectArea = length * width;
	return rectArea;
}

//When a function is called, a new stack frame is created on top of the call stack. The functions paramaeters and local variables are put onto the frame. It then goes to the next
//called function. The most recent function call will be on the top of the stack frame, so if there are nested functions the oldest will be on the bottom. When a function is returned,
//the return value is stored in a designated location and then that specific stack frame is removed, access to local variables are then lost.
//
//In our example here, the main function is first called. In this stack frame, length and width variables are stored, and printf functions are called. These printf functions don't have any variables. Next, the calculateTriArea function is called, which has the variable int area, as well as it's own length and width. It then calls the calculateRectArea, which has length and width, but no other local variables.
//
//When returning, the calculateRectArea will return the length*width to calculateTriArea, but no other variables will be thrown away. In calculateTriArea, the area variable will be returnedand then thrown away since it is local.


