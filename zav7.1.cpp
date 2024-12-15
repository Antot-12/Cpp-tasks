#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

const double rad = 57.2958;

struct coordinate {
    int x;
    int y;
};

class Point {
private:
    coordinate a, b;

    double calculate_distance(const coordinate& point) {
        return sqrt(pow(point.x, 2) + pow(point.y, 2));
    }

    double calculate_angle(const coordinate& point) {
        double distance = calculate_distance(point);
        if (distance == 0) {
            cout << "Error: Point is at the origin. Cannot calculate angle.\n";
            return 0.0;
        }
        return asin(point.x / distance) * rad;
    }

public:
    Point() {
        a.x = a.y = b.x = b.y = 0;
    }

    void move_a(int dx, int dy) {
        a.x += dx;
        a.y += dy;
    }

    void move_b(int dx, int dy) {
        b.x += dx;
        b.y += dy;
    }

    double distance_from_origin_a() {
        return calculate_distance(a);
    }

    double distance_from_origin_b() {
        return calculate_distance(b);
    }

    double angle_with_x_axis_a() {
        return calculate_angle(a);
    }

    double angle_with_x_axis_b() {
        return calculate_angle(b);
    }

    double distance_between_points() {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }

    void display_coordinates() {
        cout << "Point A: (" << a.x << ", " << a.y << ")\n";
        cout << "Point B: (" << b.x << ", " << b.y << ")\n";
    }

    void input_coordinates() {
        cout << "Enter coordinates for Point A (x y): ";
        validate_input(a.x);
        validate_input(a.y);
        cout << "Enter coordinates for Point B (x y): ";
        validate_input(b.x);
        validate_input(b.y);
    }

    void validate_input(int& value) {
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

void clr() {
    for (int i = 0; i < 40; i++) {
        cout << endl;
    }
}

int menu() {
    cout << "\n1. Enter coordinates for points\n"
         << "2. Move points\n"
         << "3. Distance to origin\n"
         << "4. Distance between points\n"
         << "5. Display coordinates\n"
         << "6. Polar coordinates\n"
         << "0. Quit\n"
         << "Enter your choice: ";
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void wait() {
    int temp;
    cout << "\nEnter any number to continue: ";
    while (!(cin >> temp)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
    }
}

int main() {
    Point myPoint;
    int choice, dx, dy;

    clr();
    while (true) {
        choice = menu();
        clr();
        switch (choice) {
            case 0:
                cout << "Exiting program.\n";
                return 0;
            case 1:
                myPoint.input_coordinates();
                break;
            case 2:
                cout << "Enter dx and dy for Point A: ";
                myPoint.validate_input(dx);
                myPoint.validate_input(dy);
                myPoint.move_a(dx, dy);
                cout << "Enter dx and dy for Point B: ";
                myPoint.validate_input(dx);
                myPoint.validate_input(dy);
                myPoint.move_b(dx, dy);
                break;
            case 3:
                cout << "Distance from origin (Point A): " << myPoint.distance_from_origin_a() << "\n";
                cout << "Distance from origin (Point B): " << myPoint.distance_from_origin_b() << "\n";
                break;
            case 4:
                cout << "Distance between points: " << myPoint.distance_between_points() << "\n";
                break;
            case 5:
                myPoint.display_coordinates();
                break;
            case 6:
                cout << "Polar coordinates for Point A: "
                     << "Distance: " << myPoint.distance_from_origin_a()
                     << ", Angle: " << myPoint.angle_with_x_axis_a() << "°\n";
                cout << "Polar coordinates for Point B: "
                     << "Distance: " << myPoint.distance_from_origin_b()
                     << ", Angle: " << myPoint.angle_with_x_axis_b() << "°\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        wait();
        clr();
    }
}
