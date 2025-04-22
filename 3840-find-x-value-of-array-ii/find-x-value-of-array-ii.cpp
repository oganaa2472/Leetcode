#include <vector>
#include <numeric>
#include <iostream>
#include <vector>

class Solution {
private:
    struct Node {
        long long product_mod_k;
        std::vector<int> prefix_counts; // size k

        Node(int k) : product_mod_k(1), prefix_counts(k, 0) {}
    };

    std::vector<Node> tree;
    int k;
    int n; // Size of nums

    // Merges the results from left and right children into the parent node v
    void merge(int v) {
        // Product of the current node is the product of its children
        tree[v].product_mod_k = (tree[2*v].product_mod_k * tree[2*v+1].product_mod_k) % k;

        // Copy prefix counts from the left child
        tree[v].prefix_counts = tree[2*v].prefix_counts;

        // Combine prefix counts from the right child with the product of the left child
        for (int r = 0; r < k; ++r) {
            if (tree[2*v+1].prefix_counts[r] > 0) {
                // If a prefix in the right child has remainder r,
                // the combined prefix (left child range + this prefix) has remainder (left_product * r) % k
                long long combined_remainder = (tree[2*v].product_mod_k * r) % k;
                tree[v].prefix_counts[combined_remainder] += tree[2*v+1].prefix_counts[r];
            }
        }
    }

    // Builds the segment tree recursively
    void build(const std::vector<int>& nums, int v, int tl, int tr) {
        if (tl == tr) {
            // Leaf node: product is the element itself, prefix count for this remainder is 1
            tree[v].product_mod_k = nums[tl] % k;
            tree[v].prefix_counts[nums[tl] % k]++;
        } else {
            int tm = (tl + tr) / 2;
            // Build left and right subtrees
            build(nums, 2*v, tl, tm);
            build(nums, 2*v+1, tm+1, tr);
            // Merge results from children
            merge(v);
        }
    }

    // Updates the value at a specific position in the segment tree
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            // Found the leaf node: update its value and prefix counts
            tree[v].product_mod_k = new_val % k;
            std::fill(tree[v].prefix_counts.begin(), tree[v].prefix_counts.end(), 0);
            tree[v].prefix_counts[new_val % k]++;
        } else {
            int tm = (tl + tr) / 2;
            // Recurse into the appropriate child
            if (pos <= tm) {
                update(2*v, tl, tm, pos, new_val);
            } else {
                update(2*v+1, tm+1, tr, pos, new_val);
            }
            // Merge results from children after update
            merge(v);
        }
    }

    // Queries the segment tree for prefix product counts in a given range [ql, qr]
    // Returns a pair: (frequency map of prefix products in intersection relative to max(tl, ql), product of intersection modulo k)
    std::pair<std::vector<int>, long long> query(int v, int tl, int tr, int ql, int qr) {
        // If the current node's range is outside the query range
        if (ql > qr || tl > qr || tr < ql) {
            // Return empty counts and multiplicative identity (1) for product
            return {std::vector<int>(k, 0), 1};
        }
        // If the current node's range is fully within the query range
        if (ql <= tl && tr <= qr) {
            // Return the node's prefix counts and product
            return {tree[v].prefix_counts, tree[v].product_mod_k};
        }

        int tm = (tl + tr) / 2;

        // Query overlaps both children
        if (ql <= tm && qr > tm) {
            // Query left child for the left part of the overlap
            auto left_res = query(2*v, tl, tm, ql, std::min(qr, tm));
            // Query right child for the right part of the overlap
            auto right_res = query(2*v+1, tm+1, tr, std::max(ql, tm+1), qr);

            // Combine results from left and right children
            std::vector<int> combined_counts = left_res.first;
            for (int r = 0; r < k; ++r) {
                if (right_res.first[r] > 0) {
                    // Prefix products from the right child are combined with the total product of the left part of the query
                    long long combined_remainder = (left_res.second * r) % k;
                    combined_counts[combined_remainder] += right_res.first[r];
                }
            }
            long long combined_product = (left_res.second * right_res.second) % k;
            return {combined_counts, combined_product};
        } else if (ql <= tm) {
            // Query is only in the left child
            return query(2*v, tl, tm, ql, qr);
        } else {
            // Query is only in the right child
            return query(2*v+1, tm+1, tr, ql, qr);
        }
    }

public:
    // Main function to process queries
    std::vector<int> resultArray(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;
        // Segment tree size is typically 4*n for safety
        tree.resize(4 * n, Node(k));

        // Build the initial segment tree
        build(nums, 1, 0, n - 1);

        std::vector<int> results;
        for (const auto& query_data : queries) {
            int index = query_data[0];
            int value = query_data[1];
            int start = query_data[2];
            int x = query_data[3];

            // Update the element in nums and the segment tree
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Query the segment tree for the range [start, n-1]
            // We need the count of prefix products relative to 'start' equal to x.
            // The query function returns prefix counts relative to the start of the queried range.
            if (start >= n) {
                // If start is beyond the array bounds, no remaining elements possible.
                results.push_back(0);
            } else {
                 // Query the segment tree for the relevant range
                 auto query_result = query(1, 0, n - 1, start, n - 1);
                 // The answer is the count of remainder 'x' in the resulting frequency map
                 results.push_back(query_result.first[x]);
            }
        }
        return results;
    }
};
