template < typename T > void pr (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	pr (u, args...);
}
