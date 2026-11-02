// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for allocator, shared_ptr, __shared_ptr_access
#include <string>  // for operator+, string, char_traits, basic_string
#include <functional> 
#include <iostream>

#include "ftxui/component/app.hpp"             // for App
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Button, Vertical, Renderer
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component.hpp"          // for Menu
#include "ftxui/dom/elements.hpp"  // for separator, text, Element, operator|, vbox, border
 
using namespace ftxui;

constexpr int maxNested = 2;
 
void Nested(std::string path, int depth = 0) {
  
  bool canDeeper = depth < maxNested;

  std::function<void()> on_goto1;
  std::function<void()> on_goto2;

  if (canDeeper){
    on_goto1 = [path, depth] { Nested(path + "/1", depth + 1); };
    on_goto2 = [path, depth] { Nested(path + "/2", depth + 1); };
  }

  auto screen = App::Fullscreen();
  auto goto_1 = Button("Test 1", on_goto1);
  auto goto_2 = Button("Test 2", on_goto2);
  auto back_button = Button("Back", screen.ExitLoopClosure());
  
  auto layout = Container::Vertical({
      goto_1,
      goto_2,
      back_button,
  });
  
  
  auto renderer = Renderer(layout, [&] {
    return vbox({
               text("path: " + path),
               text("depth:" + std::to_string(depth)),
               separator(),
               goto_1->Render(),
               goto_2->Render(),
               back_button->Render(),
           }) |
           border;
  });
  screen.Loop(renderer);
}
 
int listOptions(std::vector<std::string>& entries){
  auto screen = App::TerminalOutput();  
  int selected = 0;
  MenuOption option;
  option.on_enter = [&] {
    screen.ExitLoopClosure()(); 
    // return;
  };
 
  auto menu = Menu(&entries, &selected, option);
  // auto quit = Button("Quit", screen.ExitLoopClosure());
  auto layout = Container::Vertical( {menu} );
  auto renderer = Renderer(layout, [&] {
    return vbox({
               text("Projects"),
               separator(),
               menu->Render(),
               separator(),
               text("You picked" + entries[selected])
           }) |
           border;
  });

  screen.Loop(renderer);
  std::cout << selected << std::endl; 
  return selected;
}

int main() {

    std::vector<std::string> entries = {
      "entry 1",
      "entry 2",
      "entry 3",
      "exit"
  };

  listOptions(entries);

  // auto screen = App::Fullscreen();
  // auto button_nested = Button("Check Projects", [] { Nested(""); });
  // auto button_quit = Button("Quit", screen.ExitLoopClosure());
  // screen.Loop(Container::Vertical({
  //   button_nested,
  //     button_quit,
  // }));
  return 0;
}