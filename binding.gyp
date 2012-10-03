{
    "targets": [
        {
            "target_name": "iching",
            "sources": [ "src/node.cc" ],
            "include_dirs": ["..", "include"],
            'link_settings': {
                'libraries': [
                    './libiching.a',
                ],
            }
        }
    ]
}
