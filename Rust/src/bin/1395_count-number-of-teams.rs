impl Solution {
    pub fn num_teams(rating: Vec<i32>) -> i32 {
        let mut ans = 0;

        for i in 0..rating.len() {
            for j in (i + 1)..rating.len() {
                for k in (j + 1)..rating.len() {
                    let (ri, rj, rk) = (rating[i], rating[j], rating[k]);
                    if (ri < rj && rj < rk) || (rk < rj && rj < ri) {
                        ans += 1;
                    }
                }
            }
        }

        ans
    }
}
