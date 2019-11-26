open Jest;

describe("Root", () => {
  open Expect;

  test("true is true", () => 
    expect(true) |> toBe(true)
  );

  ()
});