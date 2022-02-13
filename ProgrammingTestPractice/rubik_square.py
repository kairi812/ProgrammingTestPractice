
class State:

    def __init__(self, cp, co, ep, eo):
        self.cp = cp # コーナーの場所を表す8次元ベクトル
        self.co = co # コーナーの向きを表す8次元ベクトル
        self.ep = ep # エッジの場所を表す12次元のベクトル
        self.eo = eo # エッジの向きを表す12次元のベクトル

    def apply_move(self, move):
        """
        操作を適用し、新しい状態を返す
        """
        new_cp = [self.cp[p] for p in move.cp]
        new_co = [(self.co[p] + move.co[i]) % 3 for i, p in enumerate(move.cp)]
        new_ep = [self.ep[p] for p in move.ep]
        new_eo = [(self.eo[p] + move.eo[i]) % 2 for i, p in enumerate(move.ep)]
        return State(new_cp, new_co, new_ep, new_eo)

r_state = State(
    [0, 2, 6, 3, 4, 1, 5, 7],
    [0, 1, 2, 0, 0, 2, 1, 0],
    [0, 5, 9, 3, 4, 2, 6, 7, 8, 1, 10, 11],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
)

r2_state = r_state.apply_move(r_state)
print(f"r2_state.cp = {r2_state.cp}")
print(f"r2_state.co = {r2_state.co}")
print(f"r2_state.ep = {r2_state.ep}")
print(f"r2_state.eo = {r2_state.eo}")