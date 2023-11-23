// bool checkRow(vector<vector<char>> grid) {
//     int size = grid.size();
    
//     for(int r1 = 0; r1 < size; r1++)
//     {
//         vector<int> nums1(256,0);

//         for(int c1 = 0; c1 < size-1; c1++) {
//             if (grid[r1][c1] != '.')
//                 nums1[(int)grid[r1][c1]] += 1;
//         }
//         for(int i1 = 0; i1 < nums1.size(); i1++) {
//             if (nums1[i1] > 1)
//                 return false;
//         }
//     }
//     return true;
// }

// bool checkCol(vector<vector<char>> grid) {
//     int size = grid.size();
    
//     for(int c2 = 0; c2 < size; c2++)
//     {
//         vector<int> nums2(256,0);

//         for(int r2 = 0; r2 < size-1; r2++){
//             if(grid[r2][c2] != '.')
//                 nums2[(int)grid[r2][c2]] += 1;
//         }
//         for(int i2 = 0; i2 < nums2.size(); i2++) {
//             if (nums2[i2] > 1)
//                 return false;
//         }
//     }
//     return true;
// }

// bool checkBox(vector<vector<char>> grid) {
//     int size = grid.size();

//     for(int r3 = 0; r3 < size; r3 += 3) {
//         for(int c3 = 0; c3 < size; c3 += 3)
//         {
//             vector<int> nums3(256, 0);

//             for(int row = r3; row < r3 + 3; row++) {
//                 for(int col = c3; col < c3 + 3; col++) {
//                     if(grid[r3][c3] != '.')
//                         nums3[(int)grid[r3][c3]] += 1;
//                 }
//             }
//             for(int i3 = 0; i3 < nums3.size(); i3++) {
//                 if (nums3[i3] > 1)
//                     return false;
//             }
//         }
//     }
//     return true;
// }

// bool solution(vector<vector<char>> grid) {
//     cout << checkRow(grid) << '\n';
//     cout << checkCol(grid) << '\n';
//     cout << checkBox(grid) << '\n';
//     return (checkRow(grid) && checkCol(grid) && checkBox(grid));
// }

bool solution(std::vector<std::vector<char>> grid) {

    // Always 9 x 9
    int size = 9;
    
    // FIRST, CHECK EACH ROW:

    for (int r1 = 0; r1 < size ; r1++) {
        
        // Store whether a #'s been seen:
        std::vector<int> beenSeen1(256,0);
        
        // Iterate through cols:
        for (int c1 = 0; c1 < size - 1; c1++) {
            
            if (grid[r1][c1] != '.') {
                beenSeen1[(int)grid[r1][c1]] += 1;
            }
        }
        
        // Check for duplicates:
        for (int i1 = 0; i1 < beenSeen1.size(); i1++) {
            if (beenSeen1[i1] > 1) {
                return false;
            }
        }
    }
    
    // THEN CHECK EACH COL:

      for ( int c2 = 0; c2 < size ; c2++) {
        
        // Store whether #'s been seen:
        std::vector<int> beenSeen2(256,0);
        
        // Iterate through cols:
        for (int r2 = 0; r2 < size - 1; r2++) {
            
            if (grid[r2][c2] != '.') {
                beenSeen2[(int)grid[r2][c2]] += 1;
            }
        }
        
        // Check for duplicates:
        for (int i2 = 0; i2 < beenSeen2.size(); i2++) {
            if (beenSeen2[i2] > 1) {
                return false;
            }
        }
        
    }
    
    // THEN CHECK EACH QUADRANT:
    
    // Outer loops:
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            // index r = r + x*3
            // index c = c + y*3
            
            // Inner loops:
            std::vector<int> beenSeen3(256,0);
            
            for (int r3 = 0; r3 < 3; r3++) {
                for (int c3 = 0; c3 < 3; c3++) {
                    if (grid[r3 + x*3][c3 + y*3] != '.') {
                        beenSeen3[(int)grid[r3 + x*3][c3 + y*3]] += 1;
                    }
                }
            }
            
            // Check for duplicates:
            for (int i3 = 0; i3 < beenSeen3.size(); i3++) {
                if (beenSeen3[i3] > 1) {
                    return false;
                }
            }
        }
    }

    
    return true;
}