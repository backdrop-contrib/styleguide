<?php
/**
 * @file
 * Provides common elements in style guide for all themes.
 */

/**
 * Implements hook_styleguide().
 */
function styleguide_styleguide() {
  $current_url = request_path();

  $items['a'] = array(
    'title' => t('Link'),
    'content' => styleguide_word(3, 'ucfirst') . ' ' . l(styleguide_word(3), 'node') . ' ' . styleguide_word(4) . '.',
  );
  $items['b'] = array(
    'title' => t('B'),
    'content' => styleguide_word(3, 'ucfirst') . ' <b>' . styleguide_word(3) . '</b> ' . styleguide_word(4) . '.',
  );
  $items['del'] = array(
    'title' => t('Delete'),
    'content' => styleguide_word(3, 'ucfirst') . ' <del>' . styleguide_word(3) . '</del> ' . styleguide_word(4) . '.',
  );
  $items['em'] = array(
    'title' => t('Emphasis'),
    'content' => styleguide_word(3, 'ucfirst') . ' <em>' . styleguide_word(3) . '</em> ' . styleguide_word(4) . '.',
  );
  $items['hr'] = array(
    'title' => t('hr'),
    'content' => styleguide_word(3, 'ucfirst') . ' <hr>' . styleguide_word(3) . '</hr> ' . styleguide_word(4) . '.',
  );
  $items['i'] = array(
    'title' => t('Italic'),
    'content' => styleguide_word(3, 'ucfirst') . ' <i>' . styleguide_word(3) . '</i> ' . styleguide_word(4) . '.',
  );
  $items['q'] = array(
    'title' => t('Quote'),
    'content' => styleguide_word(3, 'ucfirst') . ' <q>' . styleguide_word(3) . '</q> ' . styleguide_word(4) . '.',
  );
  $items['s'] = array(
    'title' => t('Strikethrough'),
    'content' => styleguide_word(3, 'ucfirst') . ' <s>' . styleguide_word(3) . '</s> ' . styleguide_word(4) . '.',
  );
  $items['small'] = array(
    'title' => t('Small'),
    'content' => styleguide_word(3, 'ucfirst') . ' <small>' . styleguide_word(3) . '</small> ' . styleguide_word(4) . '.',
  );
  $items['strong'] = array(
    'title' => t('Strong'),
    'content' => styleguide_word(3, 'ucfirst') . ' <strong>' . styleguide_word(3) . '</strong> ' . styleguide_word(4) . '.',
  );
  $items['sub'] = array(
    'title' => t('Subscript'),
    'content' => styleguide_word(3, 'ucfirst') . ' <sub>' . styleguide_word(1) . '</sub> ' . styleguide_word(4) . '.',
  );
  $items['sup'] = array(
    'title' => t('Superscript'),
    'content' => styleguide_word(3, 'ucfirst') . ' <sup>' . styleguide_word(1) . '</sup> ' . styleguide_word(4) . '.',
  );
  $items['u'] = array(
    'title' => t('Underline'),
    'content' => styleguide_word(3, 'ucfirst') . ' <u>' . styleguide_word(3) . '</u> ' . styleguide_word(4) . '.',
  );
  $items['code'] = array(
    'title' => t('Code (inline)'),
    'content' => styleguide_word(3, 'ucfirst') . ' <code>' . styleguide_word(3) . '</code> ' . styleguide_word(4) . '.',
  );

  $figure  = '<figure>';
  if (module_exists('image')) {
    $figure .= theme('image_style', array('style_name' => 'medium', 'uri' => backdrop_get_path('module', 'image') . '/images/sample.png'));
  }
  $figure .= '  <figcaption>' . t('Balloons in the Napa valley.') . '</figcaption>';
  $figure .= '</figure>';
  $items['figure'] = array(
    'title' => t('Figure / Caption'),
    'content' => $figure,
    'group' => t('Common'),
  );

  $items['blockquote'] = array(
    'title' => t('Blockquote'),
    'content' => styleguide_paragraph(1) . '<blockquote>' . styleguide_paragraph(1) . '</blockquote>' . styleguide_paragraph(1),
    'group' => t('Common'),
  );
  $items['monospace'] = array(
    'title' => t('Monospace'),
    'content' => styleguide_paragraph(1) . ' <pre><code>' . styleguide_lorem(1) . '</code></pre> ' . styleguide_paragraph(1),
    'group' => t('Common'),
  );

  $content = '';
  for ($i = 1; $i <=6; $i++) {
    $content .= "<h$i>" . "h$i: " . implode(' ', styleguide_list()) . "</h$i>";
  }
  $items['headings'] = array(
    'title' => "Headings",
    'content' => $content,
    'group' => t('Common'),
  );

  $link_button = array(
    '#theme' => 'link',
    '#text' => styleguide_word(2, 'ucfirst'),
    '#path' => '<front>',
    '#options' => array(
      'attributes' => array(
        'class' => array('button'),
      ),
    ),
  );
  $items['link-button'] = array(
    'title' => t('Link - button'),
    'content' => backdrop_render($link_button),
    'group' => t('Common'),
  );

  $items['ul'] = array(
    'title' => t('Unordered list'),
    'theme' => 'item_list',
    'variables' => array('items' => styleguide_list(), 'type' => 'ul', 'title' => styleguide_word(3, 'ucfirst')),
    'group' => t('Lists'),
  );
  $items['ol'] = array(
    'title' => t('Ordered list'),
    'theme' => 'item_list',
    'variables' => array('items' => styleguide_list(), 'type' => 'ol', 'title' => styleguide_word(3, 'ucfirst')),
    'group' => t('Lists'),
  );

  $links = array(
    '#theme' => 'links',
    '#links' => styleguide_links('<front>'),
    '#attributes' => array('class' => array('links')),
  );
  $items['links'] = array(
    'title' => t('Links'),
    'content' => backdrop_render($links),
    'group' => t('Lists'),
  );

  $links_inline = array(
    '#theme' => 'links',
    '#links' => styleguide_links('<front>'),
    '#attributes' => array('class' => array('links', 'inline')),
  );
  $items['links-inline'] = array(
    'title' => t('Links - inline'),
    'content' => backdrop_render($links_inline),
    'group' => t('Lists'),
  );

  $items['table'] = array(
    'title' => t('Basic table'),
    'theme' => 'table',
    'variables' => array('caption' => t('This is a table caption.'), 'header' => styleguide_header(), 'rows' => styleguide_rows()),
    'group' => t('Tables'),
  );
  $items['tablesort'] = array(
    'title' => t('Sortable table'),
    'theme' => 'table',
    'variables' => array('header' => styleguide_sortable_header(), 'rows' => styleguide_sortable_rows()),
    'group' => t('Tables'),
  );
  $items['tabledrag'] = array(
    'title' => t('Draggable table'),
    'theme' => 'table',
    'variables' => array('header' => styleguide_header(), 'rows' => styleguide_draggable_rows(), 'attributes' => array('id' => 'tabledrag-example'), 'sticky' => FALSE),
    'group' => t('Tables'),
  );
  backdrop_add_tabledrag('tabledrag-example', 'order', 'sibling', 'example-weight');

  // Simulate real-life messages.
  $messages = array(
    'status' => array(
      t('Every cache cleared.'),
      t('Page <em>About us</em> has been created. And this is <a href="#">a link</a>.'),
      t('The configuration options have been saved.'),
    ),
    'info' => t('The site is telling you something useful. And this is <a href="#">a link</a>.'),
    'warning' => t('The site is now in maintenance mode. Only users with the "Access site in maintenance mode" permission will be able to access the site. And this is <a href="#">a link</a>.'),
    'error' => array(
      t('You are not authorized to post comments.'),
      t('Cron run failed. And this is <a href="#">a link</a>.'),
    ),
  );
  foreach ($messages as $type => $message) {
    $content = '<div class="messages ' . $type . '"><h2 class="element-invisible">' . backdrop_ucfirst($type) . ' message</h2>';
    if (is_array($message)) {
      $content .= '<ul>';
      foreach ($message as $text) {
        $content .= '<li>' . $text . '</li>';
      }
      $content .= '</ul>';
    }
    else {
      $content .= $message;
    }
    $content .= '</div>';

    $items[$type . '-message'] = array(
      'title' => t('@type message', array('@type' => backdrop_ucfirst($type))),
      'content' => $content,
      'group' => t('Messages'),
    );
  }

  // Form elements.
  $fake = $form_state = array();
  $elements = styleguide_form($fake, $form_state);
  $basic = array();
  $fieldsets = array();
  $tabs = array();
  foreach (element_children($elements) as $key) {
    if (!isset($elements[$key]['#type']) || $elements[$key]['#type'] == 'item') {
      $markup[] = $key;
    }
    elseif ($elements[$key]['#type'] == 'fieldset') {
      $fieldsets[] = $key;
    }
    elseif ($key == 'vertical_tabs') {
      $tabs[] = $key;
    }
    // We skip these.
    elseif (in_array($elements[$key]['#type'], array('actions', 'submit', 'dropbutton', 'image_button'))) {
      $buttons[] = $key;
    }
    else {
      $basic[] = $key;
    }
  }

  $items['form'] = array(
    'title' => t('Form elements'),
    'content' => backdrop_get_form('styleguide_form', $basic),
    'group' => t('Forms'),
  );
  $items['form-actions'] = array(
    'title' => t('Buttons / Actions'),
    'content' => backdrop_get_form('styleguide_form', array('actions')),
    'group' => t('Forms'),
  );
  $items['form-fieldsets'] = array(
    'title' => t('Fieldsets'),
    'content' => backdrop_get_form('styleguide_form', $fieldsets),
    'group' => t('Forms'),
  );
  $items['form-vertical-tabs'] = array(
    'title' => t('Vertical tabs'),
    'content' => backdrop_get_form('styleguide_form', $tabs),
    'group' => t('Forms'),
  );
  $items['confirm_form'] = array(
    'title' => t('Confirm form'),
    'content' => backdrop_get_form('confirm_form', array('path' => '')),
    'group' => t('Forms')
  );

  // Use alternative item name to avoid conflict with main breadcrumb.
  $items['styleguide_breadcrumb'] = array(
    'title' => t('Breadcrumb'),
    'content' => theme('breadcrumb', array('breadcrumb' => backdrop_get_breadcrumb())),
    'group' => t('User interface')
  );
  $items['pager'] = array(
    'title' => t('Pager'),
    'content' => styleguide_pager(),
    'group' => t('User interface')
  );
  $items['progress_bar'] = array(
    'title' => t('Progress bar'),
    'content' => theme('progress_bar', array('percent' => 57, 'message' => styleguide_sentence(2))),
    'group' => t('User interface')
  );
  $items['dropbutton'] = array(
    'title' => t('Dropbutton'),
    'content' => backdrop_get_form('styleguide_form', array('dropbutton')),
    'group' => t('User interface'),
  );
  $items['dialog'] = array(
    'title' => t('Dialog'),
    'content' => styleguide_dialog(),
    'group' => t('User interface'),
  );

  $items['mark_new'] = array(
    'title' => t('Mark, new'),
    'content' => l(styleguide_sentence(), $current_url) . theme('mark', array('type' => MARK_NEW)),
    'group' => t('Misc')
  );
  $items['mark_updated'] = array(
    'title' => t('Mark, updated'),
    'content' => l(styleguide_sentence(), $current_url) . theme('mark', array('type' => MARK_UPDATED)),
    'group' => t('Misc')
  );
  $items['more_help_link'] = array(
    'title' => t('More help link'),
    'content' => styleguide_paragraph(1) . theme('more_help_link', array('url' => $current_url)),
    'group' => t('Misc')
  );
  $items['more_link'] = array(
    'title' => t('More link'),
    'content' => styleguide_paragraph(1) . theme('more_link', array('url' => $current_url, 'title' => styleguide_sentence())),
    'group' => t('Misc')
  );

  return $items;
}
