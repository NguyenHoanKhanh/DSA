#include <iostream>
#include <vector>

using namespace std;

// Hàm tính tích của một tập con của dãy a
int computeProduct(vector<int>& subset) {
    int product = 1;
    for (int num : subset) {
        product *= num;
    }
    return product;
}

// Hàm tìm tập con có tích lớn nhất của dãy a
vector<int> findMaxProductSubset(vector<int>& a) {
    int n = a.size();
    int maxProduct = 1; // Khởi tạo tích lớn nhất ban đầu
    vector<int> maxSubset;

    // Duyệt qua tất cả các tập con của dãy a
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> subset;
            for (int k = i; k <= j; k++) {
                subset.push_back(a[k]);
            }
            
            int product = computeProduct(subset);
            
            // Nếu tích của tập con này lớn hơn tích lớn nhất hiện tại
            // thì cập nhật tích lớn nhất và tập con lớn nhất
            if (product > maxProduct) {
                maxProduct = product;
                maxSubset = subset;
            }
        }
    }
    
    return maxSubset;
}

int main() {
    vector<int> a = {2, 3, -2, 4}; // Dãy số đầu vào
    vector<int> maxProductSubset = findMaxProductSubset(a);

    // In ra tập con có tích lớn nhất
    cout << "Tap con co tich lon nhat : ";
    for (int num : maxProductSubset) {
        cout << num << " ";
    }
    cout << endl;

    // In ra tích lớn nhất
    cout << "Tich lon nhat: " << computeProduct(maxProductSubset) << endl;

    return 0;
}
