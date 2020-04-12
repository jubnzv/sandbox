open Base
open Core
open Util

(* Reference: RWO chapter 6 *)
type basic_color =
  | Black | Red | Green | Yellow | Blue |  Magenta | Cyan | White

(* Specify with modules *)
module C = struct
  type basic_color = | Black | Red | Green | Yellow | Blue |  Magenta | Cyan | White
end
  C.Black

let basic_color_to_int = function
  | Black -> 0
  | Red -> 1
  | Green -> 2
  | Yellow -> 3
  | Blue -> 4
  | Magenta -> 5
  | Cyan -> 6
  | White -> 7

assert (list_equals (List.map ~f:basic_color_to_int [Red;Green]) [1;2])

let color_by_number number text =
  Printf.sprintf "\027[38;5;%dm%s\027[0m" number text

let blue = color_by_number (basic_color_to_int Blue) "Blue"
    Printf.printf "Hello %s World!\n" blue

type weight = Regular | Bold
type color =
  | Basic of basic_color * weight
  | RGB of int * int * int
  | Gray of int

let color_to_int = function
  | Basic (basic_color, weight) ->
    let base = match weight with Bold -> 8 | Regular -> 0 in
    base + basic_color_to_int basic_color
  | RGB (r,g,b) -> 16 + b + g * 6 + r * 36
  | Gray i -> 232 + i

let color_print color s =
  Printf.printf "%s\n" (color_by_number (color_to_int color) s)

color_print (Basic (Red, Bold)) "A bold red!"

color_print (Gray 4) "A muted gray"

(* Can I explicitly specify a type? *)
color_print (Gray 4) "A muted gray"


(* See: https://github.com/realworldocaml/examples/blob/v1/code/variants/logger.topscript *)
(* Note: Don't forget open Base.List *)
module Heartbeat = struct
  type t = { session_id : string; time : Time.t; status_message : string }
end

module Logon = struct
  type t = {
    session_id : string;
    time : Time.t;
    user : string;
    credentials : string;
  }
end

module Log_entry = struct
  type t = {
    session_id : string;
    time : Time.t;
    important : bool;
    message : string;
  }
end

type client_message =
  | Logon of Logon.t
  | Heartbeat of Heartbeat.t
  | Log_entry of Log_entry.t

let messages_for_user user messages =
  let user_messages, _ =
    List.fold messages ~init:([], String.Set.empty)
      ~f:(fun ((messages, user_sessions) as acc) message ->
          match message with
          | Logon m ->
            if m.Logon.user = user then
              (message :: messages, Set.add user_sessions m.Logon.session_id)
            else acc
          | Heartbeat _ | Log_entry _ ->
            let session_id =
              match message with
              | Logon m -> m.Logon.session_id
              | Heartbeat m -> m.Heartbeat.session_id
              | Log_entry m -> m.Log_entry.session_id
            in
            if Set.mem use_sessions session_id then
              (message :: messages, user_sessions)
            else acc)
  in
  List.rev use_messages

(* After refactoring *)
module Log_entry = struct
  type t = { important : bool; message : string }
end

module Heartbeat = struct
  type t = { status_message : string }
end

module Logon = struct
  type t = { user : string; credentials : string }
end

type details =
  | Logon of Logon.t
  | Heartbeat of Heartbeat.t
  | Log_entry of Log_entry.t

module Common = struct
  type t = { session_id : string; time : Time.t }
end

let messages_for_user user messages =
  let user_messages, _ =
    List.fold messages ~init:([], String.Set.empty)
      ~f:(fun ((messages, user_sessions) as acc)
           ((common, details) as message)
           ->
             let session_id = common.Common.session_id in
             match details with
             | Logon m ->
               if m.Logon.user = user then
                 (message :: messages, Set.add user_sessions session_id)
               else acc
             | Heartbeat _ | Log_entry _ ->
               if Set.mem user_sessions session_id then
                 (message :: messages, user_sessions)
               else acc)
  in
  List.rev user_messages
