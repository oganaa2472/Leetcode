
class Solution{
    data class Cell(val r: Int, val c: Int, val time: Int)

    fun swimInWater(grid: Array<IntArray>): Int {
        val n = grid.size
        val visited = Array(n) { BooleanArray(n) }
        
        // time-аар нь өсөх эрэмбээр эрэмбэлэх PriorityQueue
        val pq = PriorityQueue<Cell>(compareBy { it.time })
        
        // Эхлэх цэг: (0, 0), шаардагдах анхны хугацаа нь grid[0][0]
        pq.offer(Cell(0, 0, grid[0][0]))
        visited[0][0] = true
        
        val directions = arrayOf(
            intArrayOf(-1, 0), intArrayOf(1, 0),
            intArrayOf(0, -1), intArrayOf(0, 1)
        )
        
        while (pq.isNotEmpty()) {
            val (r, c, currentTime) = pq.poll()
            
            // Баруун доод буланд хүрсэн бол энэ нь хамгийн бага хугацаа
            if (r == n - 1 && c == n - 1) {
                return currentTime
            }
            
            for (dir in directions) {
                val nr = r + dir[0]
                val nc = c + dir[1]
                
                if (nr in 0 until n && nc in 0 until n && !visited[nr][nc]) {
                    visited[nr][nc] = true
                    // Дараагийн нүдэнд очих хугацаа нь одоогийн хугацаа болон 
                    // шинэ нүдний өндрийн хамгийн их утга байна
                    val nextTime = maxOf(currentTime, grid[nr][nc])
                    pq.offer(Cell(nr, nc, nextTime))
                }
            }
        }
        
        return 0
    }
}