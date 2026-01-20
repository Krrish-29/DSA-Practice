// 2424. Longest Uploaded Prefix
class LUPrefix {
private:
    vector<int>videos;
    int longestVideo;
public:
    LUPrefix(int n) {
        videos.resize(n+1);
        longestVideo=0;
    }
    
    void upload(int video) {
        videos[video-1]=1;
    }
    
    int longest() {
        while(videos[longestVideo]==1) longestVideo++;
        return longestVideo;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */