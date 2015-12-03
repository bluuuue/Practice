/*
***give a point in a binary image, 
***find the the edge of the same 
***color area which connects with the point
*/
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    //constructor
    Point(int a, int b){
        x = a;
        y = b;
        color = 0;
    }
    //the pos of the point
    int x;
    int y;
    //the color of the point(black=0, white=1)
    bool color;
}

bool isRange(vector<vector<int> > image, int x, int y) {
    if (image.empty() || image[0].empty) {
        cout << "Empty Image." << endl;
        return true;
    }
    if (x < 0 || x > image.size() - 1 || y < 0 || image[0].size() - 1)
        return true; //the point is a range point
    return false;
}

void Search(const vector<vector<int> > &image, vector<vector<bool> > &SearchFlag, Point pt, vector<Point> &Range) {
    if (isRange(image, pt.x, pt.y)
        return ;
    if (SearchFlag[pt.x][pt.y])
        return ;

    bool up = false, down = false, left = false, right = false;
    if (!isRange(image, pt.x - 1, pt.y)) 
        if (image[pt.x - 1][pt.y] == pt.color) {
            down = true;
            Search(image, SearchFlag, Point(pt.x - 1, pt.y), Range);
        }
    if (!isRange(image, pt.x + 1, pt.y)) 
        if (image[pt.x + 1][pt.y] == pt.color) {
            up = true;
            Search(image, SearchFlag, Point(pt.x + 1, pt.y), Range);
        }
    if (!isRange(image, pt.x, pt.y - 1)) 
        if (image[pt.x][pt.y - 1] == pt.color) {
            left = true;
            Search(image, SearchFlag, Point(pt.x, pt.y - 1), Range);
        }
    if (!isRange(image, pt.x, pt.y + 1)) 
        if (image[pt.x][pt.y + 1] == pt.color) {
            right = true;
            Search(image, SearchFlag, Point(pt.x, pt.y + 1), Range);
        }

    //if the points around the point "pt" is not all the same color, then "pt" is a range point
    if (!(up && down && left && right))
        Range.push_back(pt);

    //set the point "pt" to be searched
    SearchFlag[pt.x][pt.y] = true;
}

vector<Point> SearchRange(const vector<vector<int> > &image, Point click) {
    vector<Point> Range;
    if (isRange(image, click.x, click.y)
        return Range;
    
    //record whether has searched the point
    vector<vector<bool> > SearchFlag;
    vector<bool> TempFlag;
    for (int i = 0; i < image.size(); ++i)
        TempFlag.push_back(false);
    for (int i = 0; i < image[0].size(); ++i)
        SearchFlag.push_back(TempFlag);

    //set the point color
    click.color = image[click.x][click.y];

    Search(image, SearchFlag, click, Range);
    return Range;
}
