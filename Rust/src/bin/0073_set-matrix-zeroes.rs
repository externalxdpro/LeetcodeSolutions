impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut zeros: Vec<(usize, usize)> = vec![];
        for i in 0..matrix.len() {
            for j in 0..matrix[0].len() {
                if matrix[i][j] == 0 {
                    zeros.push((i, j));
                }
            }
        }
        for (i, j) in zeros {
            for x in 0..matrix[0].len() {
                matrix[i][x] = 0;
            }
            for y in 0..matrix.len() {
                matrix[y][j] = 0;
            }
        }
    }
}
