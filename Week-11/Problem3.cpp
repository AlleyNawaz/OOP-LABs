#include <iostream>
using namespace std;

class Post {
private:
    int likes;
    int comments;

public:
    Post(int l = 0, int c = 0) {
        likes = l;
        comments = c;
    }

    void display() {
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
    }

    friend Post totalEngagement(Post p1, Post p2);
};

Post totalEngagement(Post p1, Post p2) {
    int totalLikes = p1.likes + p2.likes;
    int totalComments = p1.comments + p2.comments;

    return Post(totalLikes, totalComments);
}

int main() {
    Post p1(120, 40);
    Post p2(300, 90);

    cout << "Post 1:\n";
    p1.display();

    cout << "Post 2:\n";
    p2.display();

    Post combined = totalEngagement(p1, p2);

    cout << "\nCombined Engagement:\n";
    combined.display();
}