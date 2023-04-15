static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class SnapshotArray {
	public:
		int timestamp = 0;
		vector<map<int, int>> data;
		SnapshotArray(int length) {
			data = vector<map<int, int>>(length);
			for (int i = 0; i < length; ++i)
				data[i][timestamp] = 0;
		}

		void set(int index, int val) {
			data[index][timestamp] = val;
		}

		int snap() {
			return timestamp++;
		}

		int get(int index, int snap_id) {
			auto it = data[index].upper_bound(snap_id);
			return (--it)->second;
		}
	};